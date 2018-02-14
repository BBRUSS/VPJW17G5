#include "camera.h"
#include <QDebug>

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


void Camera::calcBoardCornerPositions(vector<Point3f>& corners)
{
    corners.clear();

    switch(s->calibrationPattern)
    {
    case Settings::CHESSBOARD:
    case Settings::CIRCLES_GRID:
        for( int i = 0; i < s->boardSize.height; ++i )
            for( int j = 0; j < s->boardSize.width; ++j )
                corners.push_back(Point3f(float( j*s->squareSize ), float( i*s->squareSize ), 0));  // X, Y, Z
        break;

    case Settings::ASYMMETRIC_CIRCLES_GRID:
        for( int i = 0; i < s->boardSize.height; i++ )
            for( int j = 0; j < s->boardSize.width; j++ )
                corners.push_back(Point3f(float((2*j + i % 2)*s->squareSize), float(i*s->squareSize), 0));
        break;
    default:
        break;
    }
}


bool Camera::runCalibration()
{
    cameraMatrix = Mat::eye(3, 3, CV_64F);      // if(CV_CALIB_FIX_ASPECT_RATIO), some entries need to be initialzed
    distCoeffs = Mat::zeros(8, 1, CV_64F);      // (k1, k2, p1, p2 [,k3[, k4, k5, k6]]), not depending on resolution or view
    vector<vector<Point3f> > objectPoints(1);   // hold position of calibration pattern objects

    if( s->calibFlag & CV_CALIB_FIX_ASPECT_RATIO )
        cameraMatrix.at<double>(0,0) = 1.0;

    calcBoardCornerPositions(objectPoints[0]);  // Calculate corner positions
    objectPoints.resize(imagePoints.size(), objectPoints[0]);

    double error = calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, s->calibFlag);
    qInfo() << "Re-projection error reported by calibrateCamera: "<< error << endl;

    // check if calibration results neither contain NaN nor inf
    bool ok = checkRange(cameraMatrix) && checkRange(distCoeffs);
    return ok;
}


bool Camera::calibrate()
{
    // read Settings
    // run calibration
    // save Settings
    return false;
}


Mat Camera::nextImage()
{
    Mat result;
    if( inputCapture.isOpened() )
    {
        Mat view0;
        inputCapture >> view0;
        view0.copyTo(result);
    }
    else
    {
        qInfo() << "Camera "<< id << "is not opened yet!";
    }

    return result;
}


void Camera::showChessboardPattern(Size imageSize, Mat view)
{
    imageSize = view.size();  // Format input image.


    vector<Point2f> pointBuf;

    bool found;
    switch( s->calibrationPattern ) // Find feature points on the input format
    {
    case Settings::CHESSBOARD:
        found = findChessboardCorners( view, s->boardSize, pointBuf,
                                       CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FAST_CHECK | CV_CALIB_CB_NORMALIZE_IMAGE);
        break;
    case Settings::CIRCLES_GRID:
        found = findCirclesGrid( view, s->boardSize, pointBuf );
        break;
    case Settings::ASYMMETRIC_CIRCLES_GRID:
        found = findCirclesGrid( view, s->boardSize, pointBuf, CALIB_CB_ASYMMETRIC_GRID );
        break;
    default:
        found = false;
        break;
    }

    if ( found)                // If done with success,
    {
        // improve the found corners' coordinate accuracy for chessboard
        if( s->calibrationPattern == Settings::CHESSBOARD)
        {
            Mat viewGray;
            cvtColor(view, viewGray, COLOR_BGR2GRAY);
            cornerSubPix( viewGray, pointBuf, Size(11,11),
                          Size(-1,-1), TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));
        }

        if( /*mode == CAPTURING &&*/  // For camera only take new samples after delay time
                (!inputCapture.isOpened() /*|| clock() - prevTimestamp > s.delay*1e-3*CLOCKS_PER_SEC*/) )
        {
            imagePoints.push_back(pointBuf);
            //prevTimestamp = clock();
            //blinkOutput = s.inputCapture.isOpened();
        }

        // Draw the corners.
        drawChessboardCorners( view, s->boardSize, Mat(pointBuf), found );
    }
}


Mat Camera::getInputPic()
{
    Mat image;
    return image;
}


Mat Camera::getUndistortedPic()
{
    //Mat temp = view.clone();
    //undistort(temp, view, cameraMatrix, distCoeffs);
    Mat image;
    return image;
}


// According to George Lecaces Youtube video "OpenCV Basics"

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
        break;
    }
}


/** calibrate the camera with given images
 * @brief Camera::cameraCalibration
 */
void Camera::cameraCalibration(vector<Mat> calibrationImages, Size boardSize/*, Mat& cameraMatrix, Mat& distCoeffs*/)
{
    vector<vector<Point2f>> chessboardImageSpacePoints;
    getChessboardCorners(calibrationImages, chessboardImageSpacePoints, false);
    // TODO: depending on calibration pattern (Chessboard, Circle grid)
    vector<vector<Point3f>> worldSpaceCornerPoints(1);

    createKnownBoardPositions(worldSpaceCornerPoints[0]);
    worldSpaceCornerPoints.resize(chessboardImageSpacePoints.size(), worldSpaceCornerPoints[0]);

    double error = calibrateCamera(worldSpaceCornerPoints, chessboardImageSpacePoints, boardSize, cameraMatrix, distCoeffs, rvecs, tvecs);
    saveCameraCalibrationParameters();
    qInfo() << "calibration finished with error <" << error << ">" << endl;
}


/** Find the corners of calibration pattern (e.g. chessboard) in the image plane
 * and show them, if wanted.
 * @brief Camera::getChessboardCorners
 */
void Camera::getChessboardCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showFoundCorners)
{
    for(vector<Mat>::iterator i = images.begin(); i != images.end();i++)
    {
        vector<Point2f> pointBuf;
        bool found = findChessboardCorners(*i, s->boardSize, pointBuf, CV_CALIB_CB_ADAPTIVE_THRESH|CV_CALIB_CB_NORMALIZE_IMAGE);
        // TODO: depending on calibration pattern (Chessboard, Circle grid)
        if(found)
        {
            allFoundCorners.push_back(pointBuf);
        }
        // show results
        if(showFoundCorners)
        {
            drawChessboardCorners(*i, s->boardSize, pointBuf, found);
            imshow("Looking 4 Corners", *i);
            waitKey(0);
        }
    }
}


/**
 * start calibration process, this is the function to be called within GUI / SLOTs
 * @brief Camera::doCalibration
 * @return 0 if successfull, -1 if no camera was found
 */
int Camera::doCalibration()
{
    Mat frame;
    Mat drawToFrame;
    cameraMatrix = Mat::eye(3,3,CV_64F);
    distCoeffs = Mat::zeros(8,1,CV_64F);
    vector<Mat> savedImages;
    VideoCapture vid(1);

    if(!vid.isOpened()) return -1;

    int framesPerSecond = 20;

    namedWindow("Webcam", CV_WINDOW_AUTOSIZE);

    while(true)
    {
        if(!vid.read(frame)) break;

        // find and show calibration pattern corners
        // TODO: depending on calibration pattern (Chessboard, Circle grid)
        vector<Vec2f> foundPoints;
        bool found = findChessboardCorners(frame, s->boardSize, foundPoints, CV_CALIB_CB_ADAPTIVE_THRESH|CV_CALIB_CB_NORMALIZE_IMAGE|CV_CALIB_CB_FAST_CHECK);
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

            if(savedImages.size() > s->nrFrames)
            {
                qInfo() << "calibrating cam" << "<" <<id << ">" << endl;
                cameraCalibration(savedImages, s->boardSize/*, cameraMatrix, distCoeffs*/);

            }
            break;

        case ESC_KEY:
            // exit
            qInfo() << "bye bye" << endl;
            destroyWindow("Webcam");
            return 0;
            break;
        }
    }
    return 0;
}


/** Test function, actually for printing the parameters.
 * Later used for saving them in XML-File (Benny)
 * @brief Camera::saveCameraCalibrationParameters
 */
void Camera::saveCameraCalibrationParameters()
{
    qInfo() << "Camera Matrix" << endl;
    for(int r=0; r<cameraMatrix.rows;r++)
    {
        for(int c=0;c<cameraMatrix.cols;c++)
        {
            //qInfo() << cameraMatrix.at<double>(r,c);
        }
    }
    // Testoutput in matrix form
    QString buf;
    buf.sprintf( "%f %f %f", cameraMatrix.at<float>(1, 1), cameraMatrix.at<float>(1, 2), cameraMatrix.at<float>(1, 3) );
    qInfo() << buf;
    buf.sprintf( "%f %f %f", cameraMatrix.at<float>(2, 1), cameraMatrix.at<float>(2, 2), cameraMatrix.at<float>(2, 3) );
    qInfo() << buf;
    buf.sprintf( "%f %f %f", cameraMatrix.at<float>(3, 1), cameraMatrix.at<float>(3, 2), cameraMatrix.at<float>(3, 3) );
    qInfo() << buf << endl;

    qInfo() << "Distortion Coefficients" << endl;
    for(int r=0; r<distCoeffs.rows;r++)
    {
        for(int c=0;c<distCoeffs.cols;c++)
        {
            qInfo() << distCoeffs.at<double>(r,c);
        }
    }
}
