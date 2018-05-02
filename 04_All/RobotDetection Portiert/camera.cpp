#include "camera.h"
#include <QDebug>
#include <iostream>

#define ESC_KEY 27
#define ENTER_KEY 13
#define SPACE_KEY 32 // ' '

const Scalar RED(0,0,255), GREEN(0,255,0), BLUE(255,0,0), BLACK(0,0,0), WHITE(255,255,255), PINK(125,0,255);

Camera::Camera()
{
    this->id = 1;
    this->nr = 0;
    mustInitUndistort = true;
}


Camera::Camera(int nr, int id, Settings *s)
{
    this->nr = nr;
    this->id = id;
    this->s = s;
    this->cameraMatrix = s->cams.at(nr)->cameraMatrix;  //Mat::eye(3, 3, CV_64F);    // camera matrix 3x3
    this->distCoeffs = s->cams.at(nr)->distCoeffs;      //Mat::zeros(8, 1, CV_64F);    // distortion coefficients 8x1
    setContrast(-1, -1);                                // default: do not use these values, ergo -1
}


/** calculate the corners of calibration pattern (e.g. chessboard) in the real world plane
 * Note: In CIRCLES_GRID, the squareSize is the distance between two circle middlepoints!
 * @brief Camera::createKnownBoardPositions
 */
void Camera::createKnownBoardPositions(vector<Point3f>& corners, Size size, float squareSize, Settings::Pattern pattern, float xOrigin, float yOrigin)
{
    switch(pattern)
    {
    case Settings::CHESSBOARD:
    case Settings::CIRCLES_GRID:
        for(int i = 0; i < size.height; i++)    // in original example description: ++i, ++j, they leave kind of space. With i++, the first corner is (0,0)
        {
            for(int j = 0; j < size.width; j++)
            {
                corners.push_back(Point3f(xOrigin + j*squareSize, yOrigin + i*squareSize, 0.0f)); // X,Y,Z
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


/** calibrate the camera with given image space- and real world calibration points
 * @brief Camera::cameraCalibration
 * @param chessboardImageSpacePoints: vector with pixel positions of found calibration corners
 * @param worldSpaceCornerPoints : vector with real world positions of calibration corners
 * @param boardSize : Size object of calibration board dimensions
 */
void Camera::cameraCalibration(vector<vector<Point2f>> chessboardImageSpacePoints, vector<vector<Point3f>> worldSpaceCornerPoints, Size boardSize)
{
    worldSpaceCornerPoints.resize(chessboardImageSpacePoints.size(), worldSpaceCornerPoints[0]);

    cv::calibrateCamera(worldSpaceCornerPoints, chessboardImageSpacePoints, boardSize, cameraMatrix,
                        distCoeffs, rvecs, tvecs, CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);
    double error = computeReprojectionErrors(worldSpaceCornerPoints, chessboardImageSpacePoints, rvecs, tvecs, cameraMatrix, distCoeffs);
    qInfo() << "calibration finished with error <" << error << ">" << endl;
    saveCameraCalibrationParameters();
}


//The function returns the final re-projection error.
// calibrate the camera and returns the re-projection error
double Camera::cameraCalibration(Size &imageSize)
{
    // undistorter must be reinitialized
    mustInitUndistort = true;
    //Output rotations and translations vectors
    vector<Mat> rvecs, tvecs;
    int flag = 0;//CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5;

    double error = calibrateCamera(objectPoints, // the 3D points - real world 3D coordinates
                                   imagePoints,  // the image points - 2D coordinates (pixel values)
                                   imageSize,    // image size
                                   cameraMatrix, // output camera matrix
                                   distCoeffs,   // output distortion matrix
                                   rvecs, tvecs, // Rs, Ts
                                   flag);        // set options


    //Verhindern, dass Point Duplikate in den Vektor geschrieben werden.
    //In der Form 1|12|123|1234
    //Am Ende bleiben die Punkte jetzt nur in der Form 1234 im Vektor.
    //Durchgang 1: 1
    //Durchgang 2: 12
    //Durchgang 3: 123
    //Durchgang 4: 1234

    if(imagePoints.size() <= 3)
    {
        imagePoints.clear();
        objectPoints.clear();
    }

    saveCameraCalibrationParameters();  // ACTUALLY ONLY FOR OUTPUT ON CONSOLE, SAVING LATER IN GUI

    return error;
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
            if( s->calibrationPattern == Settings::CHESSBOARD||s->calibrationPattern == Settings::CIRCLES_GRID)
            {
                Mat viewGray;
                cvtColor(*i, viewGray, COLOR_BGR2GRAY);
                cornerSubPix( viewGray, pointBuf, Size(5,5),
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


/** Process to obtain extrinsic parameters.
 * You will need to put the calibration pattern to a known position in the real world.
 * @brief Camera::doCalibrationExtrinsics
 * @return 1 if successfull, -1 if no pattern was found
 */
int Camera::doCalibrationExtrinsics(Mat &image)
{
    Mat frame;
    image.copyTo(frame);

    vector<Point2f> imagePointsExtrinsic;
    vector<Point3f> objectPointsExtrinsic;

    Mat undistorted;
    undistort(frame, undistorted, cameraMatrix, distCoeffs);


    Mat detectionImage;
    if (s->calibPatternWhiteOnBlack) {
        cv::Mat Temp = cv::Scalar::all(255) - undistorted;
        Temp.copyTo(detectionImage);
    } else {
        undistorted.copyTo(detectionImage);
    }

    bool found = false;

    switch (s->calibrationPattern) {
    case Settings::Pattern::CHESSBOARD:
        found = findChessboardCorners(detectionImage, s->boardSize, imagePointsExtrinsic);
        break;
    case Settings::Pattern::CIRCLES_GRID:
        found = findCirclesGrid(detectionImage, s->boardSize, imagePointsExtrinsic, CALIB_CB_SYMMETRIC_GRID);
        break;
    case Settings::Pattern::ASYMMETRIC_CIRCLES_GRID:
        found = findCirclesGrid(detectionImage, s->boardSize, imagePointsExtrinsic, CALIB_CB_ASYMMETRIC_GRID);
        break;
    }

    if(!found)
    {
        qInfo() << "no pattern found!";
        return -1;
    }

    // Create 3D world points (TODO: Set x/y 3D coordinates)
    float xOrigin = 0;
    float yOrigin = 0;
    createKnownBoardPositions(objectPointsExtrinsic, s->boardSize, s->squareSize, s->calibrationPattern, s->extrinsicOrigin.x, s->extrinsicOrigin.y);
    /*for (int i=0; i<s->boardSize.height; i++)
    {
        for (int j=0; j<s->boardSize.width; j++)
        {
            objectPointsExtrinsic.push_back(cv::Point3f(j * s->squareSize, i * s->squareSize, 0.0f));
        }
    }
    */
    bool success = 0;
    //success = cv::solvePnP(objectPointsExtrinsic, imagePointsExtrinsic, cameraMatrix, distCoeffs, rvec, tvec);
    success = cv::solvePnP(objectPointsExtrinsic, imagePointsExtrinsic, cameraMatrix, cv::Mat(), rvec, tvec);
    qInfo() << success;
    return success;
}


/**
 * undistorts the given frame
 * @brief Camera::getUndistorted
 * @param distorted: distorted frame
 * @param cameraMatrix: intrinsics of camera
 * @param distCoeffs: distortion coefficients
 * @return undistorted frame
 */
Mat Camera::getUndistorted(Mat distorted, Mat cameraMatrix, Mat distCoeffs)
{
    Mat undistorted;
    undistort(distorted, undistorted, cameraMatrix, distCoeffs);
    return undistorted;
}


/**
 * undistorts the given frame
 * @brief Camera::getUndistorted
 * @param distorted: distorted frame
 * @return undistorted frame
 */
Mat Camera::getUndistorted(Mat distorted)
{
    Mat undistorted;
    undistort(distorted, undistorted, this->cameraMatrix, this->distCoeffs);
    return undistorted;
}


/**
 * remaps image points according to x/y mapping functions
 * @brief Camera::remap
 * @param distorted: distorted frame
 * @return
 */
Mat Camera::remap(const Mat &distorted)
{
    Mat undistorted;
    if (mustInitUndistort) { // called once per calibration - wird deswegen im Konstruktor initial auf true gesetzt
        initUndistortRectifyMap(
                    cameraMatrix,       // computed camera matrix
                    distCoeffs,         // computed distortion matrix
                    Mat(),              // optional rectification
                    getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, distorted.size(), 1, distorted.size(), 0), // camera matrix to generate undistorted
                    distorted.size(),   // size of undistorted
                    CV_32FC1,           // type of output map
                    map1, map2);        // the x and y mapping functions
        mustInitUndistort = false;
    }

    // apply mapping functions
    cv::remap(distorted, undistorted, map1, map2, INTER_LINEAR); // interpolation type

    return undistorted;
}


/** Test function, actually for printing the parameters.
 * Later used for saving them in XML-File (Benny)
 * @brief Camera::saveCameraCalibrationParameters
 */
void Camera::saveCameraCalibrationParameters()
{
    qInfo() << "Writing Camera parameters of Cam <" << nr <<"> to XML File...";
    s->cams.at(nr)->cameraMatrix = cameraMatrix;
    s->cams.at(nr)->distCoeffs = distCoeffs;
    s->cams.at(nr)->rvecs = rvec;
    s->cams.at(nr)->tvecs = tvec;
    //s->save();

    // Testoutput in matrix form
    // (remember: fx, fy are focal length in pixels, so fx = f/px with f = focal length in mm and px = pixel width
    //                                     analog:      fy = f/py with f = focal length in mm and py = pixel height)
    qInfo() << "Test Output for XML";
    qInfo() << "Camera Matrix:";
    QString buf;
    buf.sprintf( "%.2f %.2f %.2f", cameraMatrix.at<double>(0, 0), cameraMatrix.at<double>(0, 1), cameraMatrix.at<double>(0, 2) );
    qInfo() << buf; buf.clear();
    buf.sprintf( "%.2f %.2f %.2f", cameraMatrix.at<double>(1, 0), cameraMatrix.at<double>(1, 1), cameraMatrix.at<double>(1, 2) );
    qInfo() << buf; buf.clear();
    buf.sprintf( "%.2f %.2f %.2f", cameraMatrix.at<double>(2, 0), cameraMatrix.at<double>(2, 1), cameraMatrix.at<double>(2, 2) );
    qInfo() << buf << endl;

    //    qInfo() << "Distortion Coefficients:";
    //    for(int r=0; r<distCoeffs.rows;r++)
    //    {
    //        for(int c=0;c<distCoeffs.cols;c++)
    //        {
    //            qInfo() << distCoeffs.at<double>(r,c);
    //        }
    //    }
    //    qInfo() << endl;

    qInfo() << "rotational vector:";
    for(int r=0; r<rvec.rows; r++)
    {
        for(int c=0;c<rvec.cols;c++)
        {
            qInfo() << rvec.at<double>(r,c);
        }
    }
    qInfo() << endl;

    qInfo() << "translational vector:";

    for(int r=0; r<tvec.rows;r++)
    {
        for(int c=0;c<tvec.cols;c++)
        {
            qInfo() << tvec.at<double>(r,c);
        }
    }
    qInfo() << endl;
    double fovx, fovy, focalLength, aspectRatio;
    Point2d principalPoint;
    calibrationMatrixValues(cameraMatrix, s->cameraImageSize, 0.0056f*s->cameraImageSize.width, 0.0056f*s->cameraImageSize.height, fovx, fovy, focalLength, principalPoint, aspectRatio);
    qInfo() << "focalLength= " << focalLength;
    qInfo() << "Aspect ratio= " << aspectRatio;
    qInfo() << "FOV = " << fovx << " " << fovy;
    qInfo() << "C= " << principalPoint.x << "/" << principalPoint.y;
    qInfo() << "B x H =" << s->cameraImageSize.width << " x " << s->cameraImageSize.height;
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
                                          vector<vector<Point2f>> &imagePoints,
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


// open circle_grid_board images and extract corner points
int Camera::addCirclePoints(const std::vector<Mat>& imageList)
{
    // points on the circle_grid_board
    //Output Array für erkannte Kreismittelpunkte
    /* Finds the pattern in the current input. The formation of the equations aims to finding major patterns in the input:
     * in case of the circles, these are the circles themselves.
     * The position of the circles will form the result which will be written into the pointBuf vector.
     */

    vector<Point2f> pointBuf;
    vector<Point3f> circlePoints3d;
    // 3D Scene Points
    // Initialize the circle_grid_board corners in the circle_grid_board reference frame.
    // The corners are at 3D location (X,Y,Z)= (i,j,0)
    createKnownBoardPositions(circlePoints3d, s->boardSize, s->squareSize, s->calibrationPattern, 0, 0);
    /*
    for (int i=0; i<s->boardSize.height; i++)
        for (int j=0; j<s->boardSize.width; j++)
            circlePoints3d.push_back(Point3f(j * s->squareSize, i * s->squareSize, 0.0f));
    */
    // Breite: j - distanceWidth
    // Höhe: i - distanceHeight

    // 2D Image Points
    Mat image; // to contain the current circle grid image
    Mat detectionImage; //inverted or not
    int successes = 0;

    // for all viewpoints
    int listSize = (int) imageList.size();
    for (int i=0; i<listSize; i++)
    {
        // get the image in grayscale
        image = imageList[i];
        cvtColor(image, image, cv::COLOR_RGB2GRAY);

        if (s->calibPatternWhiteOnBlack) {
            cv::Mat Temp = cv::Scalar::all(255) - image;
            Temp.copyTo(detectionImage);
        } else {
            image.copyTo(detectionImage);
        }

        bool circlesGridFound = false;

        switch (s->calibrationPattern) {
        case Settings::Pattern::CHESSBOARD:
            circlesGridFound = findChessboardCorners(detectionImage, s->boardSize, pointBuf);
            break;
        case Settings::Pattern::CIRCLES_GRID:
            circlesGridFound = findCirclesGrid(detectionImage, s->boardSize, pointBuf, CALIB_CB_SYMMETRIC_GRID);
            break;
        case Settings::Pattern::ASYMMETRIC_CIRCLES_GRID:
            circlesGridFound = findCirclesGrid(detectionImage, s->boardSize, pointBuf, CALIB_CB_ASYMMETRIC_GRID);
            break;
        }

        // get subpixel accuracy on the corners

        cv::cornerSubPix(
                    image,
                    pointBuf,
                    Size(5,5),
                    Size(-1,-1),
                    TermCriteria(
                        TermCriteria::MAX_ITER +
                        TermCriteria::EPS,
                        30,      // max number of iterations
                        0.1) //min accuracy
                    );


        // if we have a good board, add it to our data
        if (pointBuf.size() == (unsigned int) s->boardSize.area()) {
            // add image and scene points from one view
            // wird hier in der for Schleife für jedes Bild aus der imageList gemacht
            // also insgesamt 4 Vektoren mit den 3D Bildpunkten (circlePoints3d) werden in objectPoints geschrieben
            addPoints(pointBuf, circlePoints3d);
            successes++;
        }
    }
    return successes;
}

// add scene points and corresponding image points
void Camera::addPoints(const vector<Point2f>& pointBuf, const vector<Point3f>& circlePoints3d)
{
    // 2D image points from one view
    imagePoints.push_back(pointBuf);
    // corresponding 3D scene points
    objectPoints.push_back(circlePoints3d);
}
