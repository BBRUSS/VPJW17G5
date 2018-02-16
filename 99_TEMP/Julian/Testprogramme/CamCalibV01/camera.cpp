#include "camera.h"
#include <QDebug>
#include <iostream>

#define ESC_KEY 27
#define ENTER_KEY 13
#define SPACE_KEY 32 // ' '

Camera::Camera(int id, Ui::MainWindow *ui, Settings *s)
{
    this->id = id;
    this->ui = ui;
    this->s = s;
    this->cameraMatrix = Mat::eye(3, 3, CV_64F);    // camera matrix 3x3
    this->distCoeffs = Mat::zeros(8, 1, CV_64F);    // distortion coefficients 8x1
    //inputCapture.open(id);
}


/** calculate the corners of calibration pattern (e.g. chessboard) in the real world plane
 * @brief Camera::createKnownBoardPositions
 */
void Camera::createKnownBoardPositions(vector<Point3f>& corners)
{
    switch(s->calibrationPattern)
    {
    case Settings::CHESSBOARD:
    case Settings::CIRCLES_GRID:
        for(int i = 0; i < s->boardSize.height; i++)    // in original example description: ++i, ++j, they leave kind of space. With i++, the first corner is (0,0)
        {
            for(int j = 0; j < s->boardSize.width; j++)
            {
                corners.push_back(Point3f(j*s->squareSize, i*s->squareSize, 0.0f)); // X,Y,Z
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
    createKnownBoardPositions(worldSpaceCornerPoints[0]);
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
int Camera::doCalibration()
{
    Mat frame;                              // Original video frame
    Mat drawToFrame;                        // Copy of original frame to draw found patterns within it
    cameraMatrix = Mat::eye(3,3,CV_64F);    // Initialize intrinsic parameters
    distCoeffs = Mat::zeros(8,1,CV_64F);    // Initialize distortion coefficients
    vector<Mat> savedImages;                // Vector for saving snapshots with found patterns
    VideoCapture vid(id);

    if(s->calibFlag & CV_CALIB_FIX_ASPECT_RATIO)
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
        if(!vid.read(frame)) break;

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
                Mat temp;
                frame.copyTo(temp);
                savedImages.push_back(temp);
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
