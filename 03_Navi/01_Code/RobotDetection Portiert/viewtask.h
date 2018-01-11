#ifndef VIEWTASK_H
#define VIEWTASK_H
#include <QVector>
#include <QThreadPool>
#include <QRunnable>
#include <QtCore>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include "constants.h"

class viewtask : public QRunnable
{

public:
    viewtask();
};

#endif // VIEWTASK_H
