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
    QByteArrayData data[12];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProcessingWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProcessingWorker_t qt_meta_stringdata_ImageProcessingWorker = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ImageProcessingWorker"
QT_MOC_LITERAL(1, 22, 9), // "updateGui"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "QList<cv::Mat>"
QT_MOC_LITERAL(4, 48, 11), // "warpedImage"
QT_MOC_LITERAL(5, 60, 18), // "QList<cv::Point3f>"
QT_MOC_LITERAL(6, 79, 14), // "robotLocations"
QT_MOC_LITERAL(7, 94, 20), // "QList<RobotPosition>"
QT_MOC_LITERAL(8, 115, 14), // "detectedRobots"
QT_MOC_LITERAL(9, 130, 15), // "finishedUDPData"
QT_MOC_LITERAL(10, 146, 9), // "timeStamp"
QT_MOC_LITERAL(11, 156, 13) // "processImages"

    },
    "ImageProcessingWorker\0updateGui\0\0"
    "QList<cv::Mat>\0warpedImage\0"
    "QList<cv::Point3f>\0robotLocations\0"
    "QList<RobotPosition>\0detectedRobots\0"
    "finishedUDPData\0timeStamp\0processImages"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcessingWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       9,    2,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QTime,    6,   10,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ImageProcessingWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageProcessingWorker *_t = static_cast<ImageProcessingWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateGui((*reinterpret_cast< QList<cv::Mat>(*)>(_a[1])),(*reinterpret_cast< QList<cv::Point3f>(*)>(_a[2])),(*reinterpret_cast< QList<RobotPosition>(*)>(_a[3]))); break;
        case 1: _t->finishedUDPData((*reinterpret_cast< QList<cv::Point3f>(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2]))); break;
        case 2: _t->processImages(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ImageProcessingWorker::*_t)(QList<cv::Mat> , QList<cv::Point3f> , QList<RobotPosition> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessingWorker::updateGui)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ImageProcessingWorker::*_t)(QList<cv::Point3f> , QTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessingWorker::finishedUDPData)) {
                *result = 1;
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ImageProcessingWorker::updateGui(QList<cv::Mat> _t1, QList<cv::Point3f> _t2, QList<RobotPosition> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageProcessingWorker::finishedUDPData(QList<cv::Point3f> _t1, QTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
