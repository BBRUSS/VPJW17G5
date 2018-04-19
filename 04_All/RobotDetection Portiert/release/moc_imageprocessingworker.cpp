/****************************************************************************
** Meta object code from reading C++ file 'imageprocessingworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imageprocessingworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocessingworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageProcessingWorker_t {
    QByteArrayData data[34];
    char stringdata0[575];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProcessingWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProcessingWorker_t qt_meta_stringdata_ImageProcessingWorker = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ImageProcessingWorker"
QT_MOC_LITERAL(1, 22, 15), // "finishedUDPData"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "QList<cv::Point3f>"
QT_MOC_LITERAL(4, 58, 14), // "robotLocations"
QT_MOC_LITERAL(5, 73, 9), // "timeStamp"
QT_MOC_LITERAL(6, 83, 21), // "requestSettingsUpdate"
QT_MOC_LITERAL(7, 105, 19), // "requestUDPIncrement"
QT_MOC_LITERAL(8, 125, 9), // "updateGui"
QT_MOC_LITERAL(9, 135, 14), // "QList<cv::Mat>"
QT_MOC_LITERAL(10, 150, 11), // "cameraImage"
QT_MOC_LITERAL(11, 162, 10), // "QList<int>"
QT_MOC_LITERAL(12, 173, 19), // "robotLocationsStd1d"
QT_MOC_LITERAL(13, 193, 28), // "QList<QList<RobotPosition> >"
QT_MOC_LITERAL(14, 222, 15), // "robotIDLocation"
QT_MOC_LITERAL(15, 238, 20), // "QList<RobotPosition>"
QT_MOC_LITERAL(16, 259, 14), // "detectedRobots"
QT_MOC_LITERAL(17, 274, 20), // "finishedRobotOffsets"
QT_MOC_LITERAL(18, 295, 18), // "QList<RobotOffset>"
QT_MOC_LITERAL(19, 314, 12), // "foundOffsets"
QT_MOC_LITERAL(20, 327, 15), // "startProcessing"
QT_MOC_LITERAL(21, 343, 14), // "stopProcessing"
QT_MOC_LITERAL(22, 358, 21), // "processSettingsUpdate"
QT_MOC_LITERAL(23, 380, 13), // "taskThreshold"
QT_MOC_LITERAL(24, 394, 15), // "taskRectMinSize"
QT_MOC_LITERAL(25, 410, 10), // "robotCount"
QT_MOC_LITERAL(26, 421, 9), // "debugMode"
QT_MOC_LITERAL(27, 431, 11), // "measureData"
QT_MOC_LITERAL(28, 443, 38), // "cv::Ptr<cv::aruco::DetectorPa..."
QT_MOC_LITERAL(29, 482, 15), // "arucoParameters"
QT_MOC_LITERAL(30, 498, 30), // "cv::Ptr<cv::aruco::Dictionary>"
QT_MOC_LITERAL(31, 529, 9), // "arucoDict"
QT_MOC_LITERAL(32, 539, 12), // "robotOffsets"
QT_MOC_LITERAL(33, 552, 22) // "calibrateOffset_ON_OFF"

    },
    "ImageProcessingWorker\0finishedUDPData\0"
    "\0QList<cv::Point3f>\0robotLocations\0"
    "timeStamp\0requestSettingsUpdate\0"
    "requestUDPIncrement\0updateGui\0"
    "QList<cv::Mat>\0cameraImage\0QList<int>\0"
    "robotLocationsStd1d\0QList<QList<RobotPosition> >\0"
    "robotIDLocation\0QList<RobotPosition>\0"
    "detectedRobots\0finishedRobotOffsets\0"
    "QList<RobotOffset>\0foundOffsets\0"
    "startProcessing\0stopProcessing\0"
    "processSettingsUpdate\0taskThreshold\0"
    "taskRectMinSize\0robotCount\0debugMode\0"
    "measureData\0cv::Ptr<cv::aruco::DetectorParameters>\0"
    "arucoParameters\0cv::Ptr<cv::aruco::Dictionary>\0"
    "arucoDict\0robotOffsets\0calibrateOffset_ON_OFF"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcessingWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       6,    0,   59,    2, 0x06 /* Public */,
       7,    0,   60,    2, 0x06 /* Public */,
       8,    5,   61,    2, 0x06 /* Public */,
      17,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,   75,    2, 0x0a /* Public */,
      21,    0,   76,    2, 0x0a /* Public */,
      22,    9,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QTime,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 3, 0x80000000 | 11, 0x80000000 | 13, 0x80000000 | 15,   10,    4,   12,   14,   16,
    QMetaType::Void, 0x80000000 | 18,   19,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 28, 0x80000000 | 30, 0x80000000 | 18, QMetaType::Bool,   23,   24,   25,   26,   27,   29,   31,   32,   33,

       0        // eod
};

void ImageProcessingWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageProcessingWorker *_t = static_cast<ImageProcessingWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finishedUDPData((*reinterpret_cast< QList<cv::Point3f>(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2]))); break;
        case 1: _t->requestSettingsUpdate(); break;
        case 2: _t->requestUDPIncrement(); break;
        case 3: _t->updateGui((*reinterpret_cast< const QList<cv::Mat>(*)>(_a[1])),(*reinterpret_cast< const QList<cv::Point3f>(*)>(_a[2])),(*reinterpret_cast< const QList<int>(*)>(_a[3])),(*reinterpret_cast< const QList<QList<RobotPosition> >(*)>(_a[4])),(*reinterpret_cast< const QList<RobotPosition>(*)>(_a[5]))); break;
        case 4: _t->finishedRobotOffsets((*reinterpret_cast< QList<RobotOffset>(*)>(_a[1]))); break;
        case 5: _t->startProcessing(); break;
        case 6: _t->stopProcessing(); break;
        case 7: _t->processSettingsUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< cv::Ptr<cv::aruco::DetectorParameters>(*)>(_a[6])),(*reinterpret_cast< cv::Ptr<cv::aruco::Dictionary>(*)>(_a[7])),(*reinterpret_cast< QList<RobotOffset>(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ImageProcessingWorker::*_t)(QList<cv::Point3f> , QTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessingWorker::finishedUDPData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ImageProcessingWorker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessingWorker::requestSettingsUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ImageProcessingWorker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessingWorker::requestUDPIncrement)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ImageProcessingWorker::*_t)(const QList<cv::Mat> , const QList<cv::Point3f> , const QList<int> , const QList<QList<RobotPosition>> , const QList<RobotPosition> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessingWorker::updateGui)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ImageProcessingWorker::*_t)(QList<RobotOffset> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessingWorker::finishedRobotOffsets)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject ImageProcessingWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageProcessingWorker.data,
      qt_meta_data_ImageProcessingWorker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ImageProcessingWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageProcessingWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessingWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ImageProcessingWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ImageProcessingWorker::finishedUDPData(QList<cv::Point3f> _t1, QTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageProcessingWorker::requestSettingsUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ImageProcessingWorker::requestUDPIncrement()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ImageProcessingWorker::updateGui(const QList<cv::Mat> _t1, const QList<cv::Point3f> _t2, const QList<int> _t3, const QList<QList<RobotPosition>> _t4, const QList<RobotPosition> _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ImageProcessingWorker::finishedRobotOffsets(QList<RobotOffset> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
