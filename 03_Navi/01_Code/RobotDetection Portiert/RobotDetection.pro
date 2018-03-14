#-------------------------------------------------
#
# Project created by QtCreator 2013-12-05T09:25:13
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt thread

INCLUDEPATH += \
    "D:/opencv/build/include" \

LIBS += \
    "-LD:/opencv/build/x64/vc14/lib" \
    -lopencv_world331

#debug:LIBS +=    -lopencv_core300d \
#    -lopencv_videoio300d \
#   -lopencv_imgcodecs300d \
#    -lopencv_highgui300d \
#    -lopencv_imgproc300d \
#    -lopencv_calib3d300d \
#    -lopencv_features2d300d \
#    -lopencv_flann300d \
#    -lopencv_aruco300d


#release:LIBS +=   -lopencv_core300d \
#    -lopencv_videoio300d \
#    -lopencv_imgcodecs300d \
#    -lopencv_highgui300d \
#    -lopencv_imgproc300d \
#    -lopencv_calib3d300d \
#    -lopencv_features2d300d \
#    -lopencv_flann300d \
#    -lopencv_aruco300d


TARGET = RobotDetection
TEMPLATE = app

SOURCES += main.cpp\
        robotdetectionmainwindow.cpp \
    myudp.cpp \
    imgtask.cpp \
    imageprocessingworker.cpp \
    arucoserializer.cpp \
    arucodictionary.cpp

HEADERS  += robotdetectionmainwindow.h \
    myudp.h \
    imgtask.h \
    constants.h \
    imageprocessingworker.h \
    arucoserializer.h \
    arucodictionary.h

FORMS    += robotdetectionmainwindow.ui

RESOURCES += \
    ressource.qrc

QMAKE_POST_LINK += copy "release\\*.exe  \"deploy\\\""

