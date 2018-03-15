#include "camera.h"
#include <QDebug>
#include <iostream>

#define ESC_KEY 27
#define ENTER_KEY 13
#define SPACE_KEY 32 // ' '

const Scalar RED(0,0,255), GREEN(0,255,0);

Camera::Camera()
{
    this->id = 1;
}


Camera::Camera(int id, Ui::MainWindow *ui, Settings *s)
{
    this->id = id;
    this->ui = ui;
    this->s = s;
    this->cameraMatrix = Mat::eye(3, 3, CV_64F);    // camera matrix 3x3
    this->distCoeffs = Mat::zeros(8, 1, CV_64F);    // distortion coefficients 8x1
    //inputCapture.open(id);
    this->maxValue = -1;                            // default: do not use these values, ergo -1
    this->blackWhiteThreshold = -1;                 // default: do not use these values, ergo -1
}


/** calculate the corners of calibration pattern (e.g. chessboard) in the real world plane
 * Note: In CIRCLES_GRID, the squareSize is the distance between two circle middlepoints!
 * @brief Camera::createKnownBoardPositions
 */
void Camera::createKnownBoardPositions(vector<Point3f>& corners, Size size, float squareSize, Settings::Pattern pattern)
{
    switch(pattern)
    {
    case Settings::CHESSBOARD:
    case Settings::CIRCLES_GRID:
        for(int i = 0; i < size.height; i++)    // in original example description: ++i, ++j, they leave kind of space. With i++, the first corner is (0,0)
        {
            for(int j = 0; j < size.width; j++)
            {
                corners.push_back(Point3f(j*squareSize, i*squareSize, 0.0f)); // X,Y,Z
            }
        }
        break;

    case Settings::ASYMMETRIC_CIRCLES_GRID:
        for( int i = 0; i < s->boardSize.height; i++ )
        {
            for( int j = 0; j < s->boardSize.width; j++ )
            {
                corners.push_back(Point3f(float((2*j + i % 2)*s->squareSize), float(i*s->squareSize), 0));
            }
        }
        break;
    }
}


/** calibrate the camera with given images
 * @brief Camera::cameraCalibration
 */
void Camera::cameraCalibration(vector<Mat> calibrationImages, Size boardSize)
{
    vector<vector<Point2f>> chessboardImageSpacePoints;
    getChessboardCorners(calibrationImages, chessboardImageSpacePoints, false);

    vector<vector<Point3f>> worldSpaceCornerPoints(1);
    createKnownBoardPositions(worldSpaceCornerPoints[0], s->boardSize, s->squareSize, s->calibrationPattern);
    worldSpaceCornerPoints.resize(chessboardImageSpacePoints.size(), worldSpaceCornerPoints[0]);

    double error = calibrateCamera(worldSpaceCornerPoints, chessboardImageSpacePoints, boardSize, cameraMatrix,
                                   distCoeffs, rvecs, tvecs, /*s->calibFlag*/CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);
    saveCameraCalibrationParameters();
    qInfo() << "calibration finished with error <" << error << ">" << endl;
}


/** Find the corners of calibration pattern (e.g. chessboard) in the image plane
 * and show them, if wanted.
 * @brief Camera::getChessboardCorners
 */
bool Camera::getChessboardCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showFoundCorners)
{
    bool found = false;
    for(vector<Mat>::iterator i = images.begin(); i != images.end();i++)
    {
        vector<Point2f> pointBuf;

        switch(s->calibrationPattern)
        {
        case Settings::CHESSBOARD:
            found = findChessboardCorners(*i, s->boardSize, pointBuf,
                                          CV_CALIB_CB_ADAPTIVE_THRESH|CV_CALIB_CB_NORMALIZE_IMAGE);
            break;
        case Settings::CIRCLES_GRID:
            found = findCirclesGrid(*i, s->boardSize, pointBuf );
            break;
        case Settings::ASYMMETRIC_CIRCLES_GRID:
            found = findCirclesGrid(*i, s->boardSize, pointBuf, CALIB_CB_ASYMMETRIC_GRID );
            break;
        default: found = false;
        }

        // save corner positions, if found
        if(found)
        {
            // improve the found corners' coordinate accuracy for chessboard
            if( s->calibrationPattern == Settings::CHESSBOARD)
            {
                Mat viewGray;
                cvtColor(*i, viewGray, COLOR_BGR2GRAY);
                cornerSubPix( viewGray, pointBuf, Size(11,11),
                              Size(-1,-1), TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));
            }
            allFoundCorners.push_back(pointBuf);
        }

        // show results
        if(showFoundCorners)
        {
            drawChessboardCorners(*i, s->boardSize, pointBuf, found);
            imshow("Webcam", *i);
            //            Mat frame = QImage((const unsigned char*)(*i.data), *i.cols, *i.rows, *i.step, QImage::Format_RGB888);
            //            ui->labelImageOrig->setPixmap(QPixmap::fromImage(frame));
            waitKey(0);
        }
    }
    return found;
}


/**
 * start calibration process, this is the function to be called within GUI / SLOTs
 * @brief Camera::doCalibration
 * @return 0 if successfull, -1 if no camera was found
 */
int Camera::doCalibrationIntrinsics()
{
    Mat frame, raw;                         // Original video frame
    Mat drawToFrame;                        // Copy of original frame to draw found patterns within it
    cameraMatrix = Mat::eye(3,3,CV_64F);    // Initialize intrinsic parameters
    distCoeffs = Mat::zeros(8,1,CV_64F);    // Initialize distortion coefficients
    vector<Mat> savedImages;                // Vector for saving snapshots with found patterns
    VideoCapture vid(id);

    if(s->cams.at(id)->calibFlag & CV_CALIB_FIX_ASPECT_RATIO)
    {
        cameraMatrix.at<float>(0,0) = 1.0f;
    }

    if(!vid.isOpened())
    {
        qInfo() << "Cam" << id << "not found!" << endl;
        return -1;
    }

    int framesPerSecond = 20;

    namedWindow("Webcam", CV_WINDOW_AUTOSIZE);


    while(true)
    {
        if(!vid.read(raw)) break;

        if(blackWhiteThreshold >= 0 && maxValue >= 0)   // if values are given, use them to set threshold in frame
        {
            Mat viewGray;
            cvtColor(raw, viewGray, COLOR_BGR2GRAY);
            threshold(viewGray, frame, blackWhiteThreshold, maxValue, THRESH_BINARY);
        }
        else    // else use original frame
        {
            raw.copyTo(frame);
        }



        // find and show calibration pattern corners
        vector<Vec2f> foundPoints;
        bool found = false;
        switch(s->calibrationPattern)
        {
        case Settings::CHESSBOARD:
            found = findChessboardCorners(frame, s->boardSize, foundPoints,
                                          CV_CALIB_CB_ADAPTIVE_THRESH|CV_CALIB_CB_NORMALIZE_IMAGE|CV_CALIB_CB_FAST_CHECK);
            break;
        case Settings::CIRCLES_GRID:
            found = findCirclesGrid(frame, s->boardSize, foundPoints );
            break;
        case Settings::ASYMMETRIC_CIRCLES_GRID:
            found = findCirclesGrid(frame, s->boardSize, foundPoints, CALIB_CB_ASYMMETRIC_GRID );
            break;
        }

        // Text output on frame
        string  msg = format("%d / %d", (int)savedImages.size(), s->nrFrames);
        int baseline = 0;
        Size textSize = getTextSize(msg, 1, 1, 1, &baseline);
        Point textOrigin(frame.cols - 2*textSize.width-10, frame.rows - 2*baseline-10);

        putText(frame, msg, textOrigin, 1,1,RED);
        frame.copyTo(drawToFrame);
        drawChessboardCorners(drawToFrame, s->boardSize, foundPoints, found);
        if(found)
        {
            imshow("Webcam", drawToFrame);
        }
        else
        {
            imshow("Webcam", frame);
        }

        // save images for calibration, and calibrate if enough good images
        char key = waitKey(1000 / framesPerSecond);

        switch(key)
        {
        case SPACE_KEY:
            // save image
            if(found)
            {
                //Mat temp;
                //frame.copyTo(temp);
                savedImages.push_back(frame);
                qInfo() << "saving image...(" << savedImages.size() << "/" << s->nrFrames << ")" << endl;
            }
            break;

        case ENTER_KEY:
            // start calibration
            if(savedImages.size() > s->nrFrames-1)
            {
                qInfo() << "calibrating cam" << "<" <<id << ">" << endl;
                cameraCalibration(savedImages, s->boardSize);
                Mat undistorted = showUndistorted(frame);
            }
            break;

        case ESC_KEY:
            // exit
            qInfo() << "bye bye" << endl;
            destroyWindow("Webcam");
            destroyWindow("Distorted | Undistorted");
            return 3;
            break;
        }
    }
    return 0;
}


/** Process to obtain extrinsic parameters.
 * You will need to take 6 shots, with the calibration device switching to the 6 known points.
 * TODO: Merge both functions and use an input-parameter to switch between extrinsic and intrinsic calibration?
 * e.g.: void Camera::doCalibration(int mode)
 * @brief Camera::doCalibrationExtrinsics
 * @return 0 if successfull, -1 if no camera was found
 */
int Camera::doCalibrationExtrinsics()
{
    Mat frame, raw;                         // Original video frame
    Mat drawToFrame;                        // Copy of original frame to draw found patterns within it
    cameraMatrix = Mat::eye(3,3,CV_64F);    // Initialize intrinsic parameters
    distCoeffs = Mat::zeros(8,1,CV_64F);    // Initialize distortion coefficients
    vector<Mat> savedImages;                // Vector for saving snapshots with found patterns
    VideoCapture vid(id);
    Size calibSize(3,2);

    if(!vid.isOpened())
    {
        qInfo() << "Cam" << id << "not found!" << endl;
        return -1;
    }

    int framesPerSecond = 20;

    namedWindow("Webcam", CV_WINDOW_AUTOSIZE);

    while(true)
    {
        if(!vid.read(raw)) break;

        if(blackWhiteThreshold >= 0 && maxValue >= 0)   // if values are given, use them to set threshold in frame
        {
            cv::threshold(raw, frame, blackWhiteThreshold, maxValue, THRESH_BINARY);
        }
        else    // else use original frame
        {
            raw.copyTo(frame);
        }

        // find and show calibration pattern corners
        // TODO: convert frame to black and white with high contrast (see CalibResizing.pro)
        //        vector<Vec2f> foundPoints;
        //        bool found = findCirclesGrid(frame, Size(2,1), foundPoints );


        //        frame.copyTo(drawToFrame);
        //        drawChessboardCorners(drawToFrame, Size(2,1), foundPoints, found);
        //        if(found)
        //        {
        //            imshow("Webcam", drawToFrame);
        //        }
        //        else
        //        {
        //            imshow("Webcam", frame);
        //        }
        // save images for calibration, and calibrate if enough good images
        char key = waitKey(1000 / framesPerSecond);
        bool found = true;
        switch(key)
        {
        case SPACE_KEY:
            // save image
            if(found)
            {
                Mat temp;
                frame.copyTo(temp);
                savedImages.push_back(temp);
                qInfo() << "saving image...(" << savedImages.size() << "/" << 6 << ")" << endl;
            }
            break;

        case ENTER_KEY:
            // start calibration
            if(savedImages.size() > 6-1)
            {
                // TODO: Put all 6 images together with cv::add
                // TODO: create known circle position in 3D real world
                // TODO: find circles in image plane
                Mat images = Mat::zeros(savedImages.at(0).rows, savedImages.at(0).cols, savedImages.at(0).type());
                savedImages.at(0).copyTo(images);
                //                for(int i=0; i<savedImages.size(); i++)
                //                {
                //                    Mat temp;
                //                    savedImages.at(i).copyTo(temp);
                //                    cv::add(images, temp, images);
                //                    qInfo() << "add successfull" << i;
                //                }

                // 1. Find circle positions in image plane
                vector<Vec2f> foundPoints;
                Mat drawToImages;
                bool foundCircles = false;
                while(!foundCircles)
                {
                    found = findCirclesGrid(images, Size(3,2), foundPoints );

                    images.copyTo(drawToImages);
                    drawChessboardCorners(drawToImages, Size(3,2), foundPoints, found);
                    if(found)
                    {
                        imshow("Webcam", drawToImages);
                    }
                    else
                    {
                        imshow("Webcam", images);
                    }
                    if(waitKey(50)==ESC_KEY) break;
                }

                // 2. Create circle positions in real 3D world
                vector<vector<Point3f>> corners(1);
                createKnownBoardPositions(corners[0], Size(3,2), 13.0, Settings::CIRCLES_GRID);

                corners.resize(foundPoints.size(), corners[0]);




                //                qInfo() << "calibrating cam" << "<" <<id << ">" << endl;
                //                Mat origCameraMatrix, origDistCoeffs;

                //                cameraMatrix.copyTo(origCameraMatrix);  // save original camera Matrix
                //                distCoeffs.copyTo(origDistCoeffs);      // save original distortion coefficients
                //                double error = calibrateCamera(corners, foundPoints, Size(3,2), cameraMatrix,
                //                                               distCoeffs, rvecs, tvecs, CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);
                //                //                // TODO: calculate reprojection error with new camera matrix, compare to original ones
                //                //                // and decide, which to use
                //                origCameraMatrix.copyTo(cameraMatrix);  // restore original camera Matrix
                //                origDistCoeffs.copyTo(origDistCoeffs);  // restore original distortion coefficients
                //                //                //cout << rvecs << endl;
                //                //                //cout << tvecs << endl;
            }
            break;

        case ESC_KEY:
            // exit
            qInfo() << "bye bye" << endl;
            destroyAllWindows();
            return 0;
            break;
        }
    }
    return 0;

}


/**
 * undistorts the given frame, puts both frames together via horizontal
 * concatenation and shows the new frame for comparison.
 * @brief Camera::showUndistorted
 * @param distorted frame
 * @return undistorted frame
 */
Mat Camera::showUndistorted(Mat distorted)
{
    Mat undistorted;
    undistort(distorted, undistorted, cameraMatrix, distCoeffs);
    // put both frames together for comparison
    Mat compareFrame;
    hconcat(distorted, undistorted, compareFrame);
    imshow("Distorted | Undistorted", compareFrame);
    return undistorted;
}



/** Test function, actually for printing the parameters.
 * Later used for saving them in XML-File (Benny)
 * @brief Camera::saveCameraCalibrationParameters
 */
void Camera::saveCameraCalibrationParameters()
{
    qInfo() << "Camera Matrix (cout):" << endl;
    cout << " " << cameraMatrix << endl;
    //    for(int r=0; r<cameraMatrix.rows;r++)
    //    {
    //        for(int c=0;c<cameraMatrix.cols;c++)
    //        {
    //            //qInfo() << cameraMatrix.at<double>(r,c);
    //        }
    //    }

    // Testoutput in matrix form
    // (remember: fx, fy are focal length in pixels, so fx = f/px with f = focal length in mm and px = pixel width
    //                                     analog:      fy = f/py with f = focal length in mm and py = pixel height)
    qInfo() << "Camera Matrix (qInfo):" << endl;
    QString buf;
    buf.sprintf( "%.2f %.2f %.2f", cameraMatrix.at<double>(0, 0), cameraMatrix.at<double>(0, 1), cameraMatrix.at<double>(0, 2) );
    qInfo() << buf; buf.clear();
    buf.sprintf( "%.2f %.2f %.2f", cameraMatrix.at<double>(1, 0), cameraMatrix.at<double>(1, 1), cameraMatrix.at<double>(1, 2) );
    qInfo() << buf; buf.clear();
    buf.sprintf( "%.2f %.2f %.2f", cameraMatrix.at<double>(2, 0), cameraMatrix.at<double>(2, 1), cameraMatrix.at<double>(2, 2) );
    qInfo() << buf << endl;

    qInfo() << "Distortion Coefficients:" << endl;
    for(int r=0; r<distCoeffs.rows;r++)
    {
        for(int c=0;c<distCoeffs.cols;c++)
        {
            qInfo() << distCoeffs.at<double>(r,c);
        }
    }

    //    qInfo() << "rotational vectors:" << endl;

    //        for(int r=0; r<rvecs.size(); r++)
    //        {
    //            qInfo() << rvecs.at(r);
    //        }

    //    qInfo() << "translational vectors:" << endl;

    //        for(int r=0; r<tvecs.size(); r++)
    //        {
    //            qInfo() << tvecs.at(r);
    //        }

}





