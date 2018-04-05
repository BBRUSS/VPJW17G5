#include "camera.h"
#include <QDebug>
#include <iostream>

#define ESC_KEY 27
#define ENTER_KEY 13
#define SPACE_KEY 32 // ' '

const Scalar RED(0,0,255), GREEN(0,255,0), BLUE(255,0,0), BLACK(0,0,0), WHITE(255,255,255);

Camera::Camera()
{
    this->id = 1;
    this->nr = 0;
}


Camera::Camera(int nr, int id, Ui::MainWindow *ui, Settings *s)
{
    this->nr = nr;
    this->id = id;
    this->ui = ui;
    this->s = s;
    this->cameraMatrix = s->cams.at(nr)->cameraMatrix;  //Mat::eye(3, 3, CV_64F);    // camera matrix 3x3
    this->distCoeffs = s->cams.at(nr)->distCoeffs;      //Mat::zeros(8, 1, CV_64F);    // distortion coefficients 8x1
    setContrast(-1, -1);                                // default: do not use these values, ergo -1
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
                corners.push_back(Point3f(float((2*j + i % 2)*s->squareSize), float(i*s->squareSize), 0.0f));
            }
        }
        break;
    }
}


/** calibrate the camera with given images
 * @brief Camera::cameraCalibration
 * @param calibrationImages : vector of images with found calibration patterns
 * @param boardSize : Size object of calibration board dimensions
 */
void Camera::cameraCalibration(vector<Mat> calibrationImages, Size boardSize)
{
    vector<vector<Point2f>> chessboardImageSpacePoints;
    getCalibPatternCorners(calibrationImages, chessboardImageSpacePoints, false);

    vector<vector<Point3f>> worldSpaceCornerPoints(1);
    createKnownBoardPositions(worldSpaceCornerPoints[0], s->boardSize, s->squareSize, s->calibrationPattern);
    worldSpaceCornerPoints.resize(chessboardImageSpacePoints.size(), worldSpaceCornerPoints[0]);

    double error = calibrateCamera(worldSpaceCornerPoints, chessboardImageSpacePoints, boardSize, cameraMatrix,
                                   distCoeffs, rvecs, tvecs, CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);
    saveCameraCalibrationParameters();
    qInfo() << "calibration finished with error <" << error << ">" << endl;
}


/** calibrate the camera with given image space- and real world calibration points
 * @brief Camera::cameraCalibration
 * @param chessboardImageSpacePoints: vector with pixel positions of found calibration corners
 * @param worldSpaceCornerPoints : vector with real world positions of calibration corners
 * @param boardSize : Size object of calibration board dimensions
 */
void Camera::cameraCalibration(vector<vector<Point2f>> chessboardImageSpacePoints, vector<vector<Point3f>> worldSpaceCornerPoints, Size boardSize)
{
    qInfo() << "1 objectpoints size " << worldSpaceCornerPoints[0].size();
    qInfo() << "1 imagepoints size " << chessboardImageSpacePoints[0].size();

    worldSpaceCornerPoints.resize(chessboardImageSpacePoints.size(), worldSpaceCornerPoints[0]);

    qInfo() << "2 objectpoints size " << worldSpaceCornerPoints[0].size();
    qInfo() << "2 imagepoints size " << chessboardImageSpacePoints[0].size();
    double error = calibrateCamera(worldSpaceCornerPoints, chessboardImageSpacePoints, boardSize, cameraMatrix,
                                   distCoeffs, rvecs, tvecs, CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);
    saveCameraCalibrationParameters();
    qInfo() << "calibration finished with error <" << error << ">" << endl;
}


/** Find the corners of calibration pattern (e.g. chessboard) in the image plane
 * and show them, if wanted.
 * @brief Camera::getCalibPatternCorners
 * @param images: vector of images with calibration pattern
 * @param allFoundCorners : vector to store the found corner positions into
 * @param showFoundCorners : Flag to set wether the found corners should be drawn into the picture or not
 */
bool Camera::getCalibPatternCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showFoundCorners)
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
    vector<Point2f> foundPoints;
    vector<vector<Point2f>> savedImagePoints;
    bool found = false;

    if(s->cams.at(nr)->calibFlag & CV_CALIB_FIX_ASPECT_RATIO)
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
        // TODO: calibPatternWhiteOnBlack in Settings einarbeiten
        else if(s->calibPatternWhiteOnBlack)            // invert frame to black on white
        {
            Mat viewGray;
            cvtColor(raw, viewGray, COLOR_BGR2GRAY);
            frame = cv::Scalar::all(255) - viewGray;
        }
        else    // else use original frame
        {
            raw.copyTo(frame);
        }



        // find and show calibration pattern corners
        switch(s->calibrationPattern)
        {
        case Settings::CHESSBOARD:
            found = findChessboardCorners(frame, s->boardSize, foundPoints,
                                          CV_CALIB_CB_ADAPTIVE_THRESH|CV_CALIB_CB_NORMALIZE_IMAGE|CV_CALIB_CB_FAST_CHECK);
            break;
        case Settings::CIRCLES_GRID:
        {
            SimpleBlobDetector::Params params;
            params.minArea = 10;
            params.minDistBetweenBlobs = 5;
            const Ptr<FeatureDetector>& blobDetector = SimpleBlobDetector::create(params);

            found = findCirclesGrid(frame, s->boardSize, foundPoints, CALIB_CB_SYMMETRIC_GRID, blobDetector );
            break;
        }
        case Settings::ASYMMETRIC_CIRCLES_GRID:
            found = findCirclesGrid(frame, s->boardSize, foundPoints, CALIB_CB_ASYMMETRIC_GRID );
            break;
        }

        // Text output on frame
        string  msg = format("%d / %d", (int)savedImages.size(), s->nrFrames);
        int baseline = 0;
        Size textSize = getTextSize(msg, 1, 1, 1, &baseline);
        Point textOrigin(frame.cols - 2*textSize.width-10, frame.rows - 2*baseline-10);

        // Decide Text color
        if(s->calibPatternWhiteOnBlack)
        {
            putText(frame, msg, textOrigin, 1, 1, WHITE);
        }
        else
        {
            putText(frame, msg, textOrigin, 1, 1, RED);
        }

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
            // save image and found points
            if(found)
            {
                savedImages.push_back(frame);
                savedImagePoints.push_back(foundPoints);
                qInfo() << "saving image...(" << savedImages.size() << "/" << s->nrFrames << ")" << endl;
            }
            break;

        case ENTER_KEY:
            // start calibration
            if(savedImages.size() > s->nrFrames-1)
            {
                qInfo() << "calibrating cam <" << nr << "> with id <" <<id << ">" << endl;
                vector<vector<Point3f>> worldSpaceCornerPoints(1);
                createKnownBoardPositions(worldSpaceCornerPoints[0], s->boardSize, s->squareSize, s->calibrationPattern);
                cameraCalibration(savedImagePoints, worldSpaceCornerPoints, s->boardSize);
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
 * @brief Camera::doCalibrationExtrinsics
 * @return 0 if successfull, -1 if no camera was found
 */
int Camera::doCalibrationExtrinsics()
{
    Size calibSizeExtrinsic(9,6);           // Size of calibration pattern for extrinsic calibration
    Mat frame, raw;                         // Original video frame
    Mat drawToFrame;                        // Copy of original frame to draw found patterns within it
    Mat images;                             // hold overlayed images
    //cameraMatrixNew = Mat::eye(3,3,CV_64F);    // Initialize intrinsic parameters
    //distCoeffsNew = Mat::zeros(8,1,CV_64F);    // Initialize distortion coefficients
    vector<Mat> savedImages;                // Vector for saving snapshots with found patterns
    VideoCapture vid(id);
    vector<Point2f> foundPoints;            // Found points in image plane
    vector<vector<Point2f>> savedImagePoints;
    bool found = false;

    if(s->cams.at(nr)->calibFlag & CV_CALIB_FIX_ASPECT_RATIO)
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
        // TODO: calibPatternWhiteOnBlack in Settings einarbeiten
        else if(s->calibPatternWhiteOnBlack)            // invert frame to black on white
        {
            Mat viewGray;
            cvtColor(raw, viewGray, COLOR_BGR2GRAY);
            frame = cv::Scalar::all(255) - viewGray;
        }
        else    // else use original frame in B/W
        {
            cvtColor(raw, frame, COLOR_BGR2GRAY);
        }
        threshold(frame, frame, 128, 255, THRESH_BINARY);


        // find and show calibration pattern corners
        SimpleBlobDetector::Params params;
        params.minArea = 10;
        params.minDistBetweenBlobs = 5;
        const Ptr<FeatureDetector>& blobDetector = SimpleBlobDetector::create(params);

        //bool testfound = findCirclesGrid(frame, calibSizeExtrinsic, foundPoints, CALIB_CB_SYMMETRIC_GRID, blobDetector );
        bool testfound = findChessboardCorners(frame,calibSizeExtrinsic,foundPoints); //ONLY FOR TESTING WITH CHESSBOARD
        // Text output on frame
        string  msg = format("%d / %d", (int)savedImages.size(), 6);
        int baseline = 0;
        Size textSize = getTextSize(msg, 1, 1, 1, &baseline);
        Point textOrigin(frame.cols - 2*textSize.width-10, frame.rows - 2*baseline-10);

        // Decide Text color
        if(s->calibPatternWhiteOnBlack)
        {
            putText(frame, msg, textOrigin, 1, 1, WHITE);
        }
        else
        {
            putText(frame, msg, textOrigin, 1, 1, BLACK);
        }

        frame.copyTo(drawToFrame);
        drawChessboardCorners(drawToFrame, calibSizeExtrinsic, foundPoints, testfound);
        if(testfound)
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
            // save image and found points
            savedImages.push_back(frame);
            qInfo() << "saving image...(" << savedImages.size() << "/" << 6 << ")" << endl;
            // break;

            // case ENTER_KEY:
            // start calibration
            // 1. Overlay all pictures into one picture

            if(savedImages.size() > /*calibSizeExtrinsic.area()*/6-1)
            {
                qInfo() << "Enough frames, start adding them...";
                // TODO: Put all 6 images together with cv::add
                // TODO: create known circle position in 3D real world
                // TODO: find circles in image plane
                images = Mat::zeros(savedImages.at(0).rows, savedImages.at(0).cols, savedImages.at(0).type());

                for(int i=0; i<savedImages.size(); i++)
                {
                    Mat temp;
                    savedImages.at(i).copyTo(temp);
                    savedImages.at(i).copyTo(images);//cv::add(images, temp, images);
                    qInfo() << "add successfull" << i;
                }
                imshow("Test-Add",images);

                // 2. Find circle positions in image plane
                qInfo() << "Searching for calibration corners ...";
                Mat drawToImages;
                while(!found)
                {
                    //found = findCirclesGrid(images, calibSizeExtrinsic, foundPoints );
                    found = findChessboardCorners(images,calibSizeExtrinsic,foundPoints);//ONLY FOR TESTING WITH CHESSBOARD
                    if(found) {savedImagePoints.push_back(foundPoints); qInfo() << "added foundPoints " << savedImagePoints.size();}

                    images.copyTo(drawToImages);
                    drawChessboardCorners(drawToImages, calibSizeExtrinsic, foundPoints, found);
                    if(found)
                    {
                        imshow("Webcam", drawToImages);
                    }
                    else
                    {
                        imshow("Webcam", images);
                    }
                    if(waitKey(33)==ESC_KEY) break;
                }

                if(found)
                {
                    // 3. Create circle positions in real 3D world
                    qInfo() << "Corners found, creating real 3D world corner positions...";
                    vector<vector<Point3f>> worldSpaceCornerPoints(1);  // 3x2 = width x height
                    // createKnownBoardPositions(worldSpaceCornerPoints[0], calibSizeExtrinsic, 13.0, Settings::CIRCLES_GRID);
                    // World space corners with home calib pattern (TODO: Offsets abhängig von Kameraposition in globalen Koordinaten)
                    for(int i = 0; i < calibSizeExtrinsic.height; i++)    // in original example description: ++i, ++j, they leave kind of space. With i++, the first corner is (0,0)
                    {
                        for(int j = 0; j < calibSizeExtrinsic.width; j++)
                        {
                            worldSpaceCornerPoints[0].push_back(Point3f(j*43.0f, i*70.0f, 0.0f)); // X,Y,Z
                        }
                    }

                    worldSpaceCornerPoints.resize(savedImagePoints.size(), worldSpaceCornerPoints[0]);

                    // 4. Calibration process
                    Mat origCameraMatrix, origDistCoeffs;
                    cameraMatrix.copyTo(origCameraMatrix);  // save original camera Matrix
                    distCoeffs.copyTo(origDistCoeffs);      // save original distortion coefficients
                    qInfo() << "calibrating cam <" << nr << "> with id <" <<id << ">" << endl;
                    rvecs.clear(); tvecs.clear(); // TESTING
                    double error = calibrateCamera(worldSpaceCornerPoints, savedImagePoints, calibSizeExtrinsic, cameraMatrix,
                                                   distCoeffs, rvecs, tvecs, CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);

                    qInfo() << "finished with error <" << error << ">";
                    //                    // 5. calculate reprojection error with new camera matrix, compare to original one
                    //                    //    and decide, which to use
                    //                    double origError = computeReprojectionErrors(worldSpaceCornerPoints, foundPoints, rvecs, tvecs, origCameraMatrix, origDistCoeffs);
                    //                    double newError = computeReprojectionErrors(worldSpaceCornerPoints, foundPoints, rvecs, tvecs, cameraMatrix, distCoeffs);
                    //                    qInfo() << "orig. Reprojection Error: " << origError << " - new one: " << newError << endl;
                    //                    if(origError < newError)
                    //                    {
                    //                        origCameraMatrix.copyTo(cameraMatrix);  // restore original camera Matrix
                    //                        origDistCoeffs.copyTo(origDistCoeffs);  // restore original distortion coefficients
                    //                    }
                    // cout << rvecs << endl;
                    // cout << tvecs << endl;
                    saveCameraCalibrationParameters();
                    found = false;
                    testfound = false;
                    savedImages.clear();
                    savedImagePoints.clear();
                    rvecs.clear();
                    tvecs.clear();
                }
            }
            break;


        case ESC_KEY:
            // exit
            qInfo() << "bye bye" << endl;
            destroyWindow("Webcam");
            destroyWindow("Test-Add");
            return 3;
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
    s->cams.at(nr)->cameraMatrix = cameraMatrix;
    s->cams.at(nr)->distCoeffs = distCoeffs;
    s->cams.at(nr)->rvecs = rvec;
    s->cams.at(nr)->tvecs = tvec;
    s->save();
    qInfo() << "Camera Matrix (cout):";
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
    qInfo() << "Camera Matrix (qInfo):";
    QString buf;
    buf.sprintf( "%.2f %.2f %.2f", cameraMatrix.at<double>(0, 0), cameraMatrix.at<double>(0, 1), cameraMatrix.at<double>(0, 2) );
    qInfo() << buf; buf.clear();
    buf.sprintf( "%.2f %.2f %.2f", cameraMatrix.at<double>(1, 0), cameraMatrix.at<double>(1, 1), cameraMatrix.at<double>(1, 2) );
    qInfo() << buf; buf.clear();
    buf.sprintf( "%.2f %.2f %.2f", cameraMatrix.at<double>(2, 0), cameraMatrix.at<double>(2, 1), cameraMatrix.at<double>(2, 2) );
    qInfo() << buf << endl;

    qInfo() << "Distortion Coefficients:";
    for(int r=0; r<distCoeffs.rows;r++)
    {
        for(int c=0;c<distCoeffs.cols;c++)
        {
            qInfo() << distCoeffs.at<double>(r,c);
        }
    }
    qInfo() << endl;

    qInfo() << "rotational vector:";
    for(int i=0; i<rvecs.size();i++)
    {
        for(int r=0; r<rvecs.at(i).rows;r++)
        {
            for(int c=0;c<rvecs.at(i).cols;c++)
            {
                qInfo() << i << ": " << "("<<r<<","<<c<<")" << rvecs.at(i).at<double>(r,c);
            }
        }
    }
    qInfo() << endl;

    qInfo() << "translational vector:";
    for(int i=0; i<tvecs.size();i++)
    {
        for(int r=0; r<tvecs.at(i).rows;r++)
        {
            for(int c=0;c<tvecs.at(i).cols;c++)
            {
                qInfo() << i << ": " << "("<<r<<","<<c<<")" << tvecs.at(i).at<double>(r,c);
            }
        }
    }
    qInfo() << endl;
}


int Camera::getID()
{
    return id;
}


void Camera::setContrast(int blackWhiteThreshold, int maxValue)
{
    this->blackWhiteThreshold = blackWhiteThreshold;
    this->maxValue = maxValue;
    s->cams.at(this->nr)->blackWhiteThreshold = blackWhiteThreshold;
    s->cams.at(this->nr)->maxValue = maxValue;
    qInfo() <<"Cam" << this->nr << " B/W Thr.:" <<  s->cams.at(this->nr)->blackWhiteThreshold << ", Max val: " << s->cams.at(this->nr)->maxValue;
}


/**
 * Compute the reprojection error to evaluate the quality of camera calibration
 * @brief Camera::computeReprojectionErrors
 * @param objectPoints - in real 3D world
 * @param imagePoints  - in 2D image plane
 * @param rvecs - rotational matrizes
 * @param tvecs - translation vectors
 * @param cameraMatrix - camera matrix (intrinsics)
 * @param distCoeffs - distortion coefficients
 * @return reprojection error
 */
double Camera::computeReprojectionErrors( vector<vector<Point3f>> &objectPoints,
                                          vector<Point2f> &imagePoints,
                                          vector<Mat> &rvecs, vector<Mat> &tvecs,
                                          Mat &cameraMatrix, Mat &distCoeffs)
{
    vector<Point2f> imagePoints2;
    int i, totalPoints = 0;
    double totalErr = 0, err;

    for( i = 0; i < (int)objectPoints.size(); ++i )
    {
        // Compute projection of 3D points to the image plane with given extrinsic and intrinsic parameters
        projectPoints( Mat(objectPoints[i]), rvecs[i], tvecs[i], cameraMatrix,  // project
                       distCoeffs, imagePoints2);
        err = norm(Mat(imagePoints[i]), Mat(imagePoints2), CV_L2);              // difference

        int n = (int)objectPoints[i].size();

        totalErr        += err*err;                                             // sum it up
        totalPoints     += n;
    }

    return std::sqrt(totalErr/totalPoints);              // calculate the arithmetical mean
}
