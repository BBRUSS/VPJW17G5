/****************************************************************************
** Meta object code from reading C++ file 'robotdetectionmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../robotdetectionmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotdetectionmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RobotDetectionMainWindow_t {
    QByteArrayData data[22];
    char stringdata0[440];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotDetectionMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotDetectionMainWindow_t qt_meta_stringdata_RobotDetectionMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 24), // "RobotDetectionMainWindow"
QT_MOC_LITERAL(1, 25, 14), // "updateGuiImage"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 14), // "QList<cv::Mat>"
QT_MOC_LITERAL(4, 56, 11), // "warpedImage"
QT_MOC_LITERAL(5, 68, 18), // "QList<cv::Point3f>"
QT_MOC_LITERAL(6, 87, 14), // "robotLocations"
QT_MOC_LITERAL(7, 102, 20), // "QList<RobotPosition>"
QT_MOC_LITERAL(8, 123, 14), // "detectedRobots"
QT_MOC_LITERAL(9, 138, 36), // "on_pushButtonCalibrateOffset_..."
QT_MOC_LITERAL(10, 175, 30), // "on_pushButtonStartStop_clicked"
QT_MOC_LITERAL(11, 206, 10), // "fpsCounter"
QT_MOC_LITERAL(12, 217, 15), // "updateIDNameMap"
QT_MOC_LITERAL(13, 233, 30), // "on_pushButton_addAruco_clicked"
QT_MOC_LITERAL(14, 264, 24), // "on_tabMain_tabBarClicked"
QT_MOC_LITERAL(15, 289, 5), // "index"
QT_MOC_LITERAL(16, 295, 32), // "on_tableWidget_Aruco_cellChanged"
QT_MOC_LITERAL(17, 328, 3), // "row"
QT_MOC_LITERAL(18, 332, 6), // "column"
QT_MOC_LITERAL(19, 339, 32), // "on_tableWidget_Aruco_cellClicked"
QT_MOC_LITERAL(20, 372, 33), // "on_pushButton_deleteAruco_cli..."
QT_MOC_LITERAL(21, 406, 33) // "on_pushButton_SaveToImage_cli..."

    },
    "RobotDetectionMainWindow\0updateGuiImage\0"
    "\0QList<cv::Mat>\0warpedImage\0"
    "QList<cv::Point3f>\0robotLocations\0"
    "QList<RobotPosition>\0detectedRobots\0"
    "on_pushButtonCalibrateOffset_clicked\0"
    "on_pushButtonStartStop_clicked\0"
    "fpsCounter\0updateIDNameMap\0"
    "on_pushButton_addAruco_clicked\0"
    "on_tabMain_tabBarClicked\0index\0"
    "on_tableWidget_Aruco_cellChanged\0row\0"
    "column\0on_tableWidget_Aruco_cellClicked\0"
    "on_pushButton_deleteAruco_clicked\0"
    "on_pushButton_SaveToImage_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotDetectionMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,
      16,    2,   84,    2, 0x08 /* Private */,
      19,    2,   89,    2, 0x08 /* Private */,
      20,    0,   94,    2, 0x08 /* Private */,
      21,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RobotDetectionMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotDetectionMainWindow *_t = static_cast<RobotDetectionMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateGuiImage((*reinterpret_cast< const QList<cv::Mat>(*)>(_a[1])),(*reinterpret_cast< const QList<cv::Point3f>(*)>(_a[2])),(*reinterpret_cast< const QList<RobotPosition>(*)>(_a[3]))); break;
        case 1: _t->on_pushButtonCalibrateOffset_clicked(); break;
        case 2: _t->on_pushButtonStartStop_clicked(); break;
        case 3: _t->fpsCounter(); break;
        case 4: _t->updateIDNameMap(); break;
        case 5: _t->on_pushButton_addAruco_clicked(); break;
        case 6: _t->on_tabMain_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_tableWidget_Aruco_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->on_tableWidget_Aruco_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->on_pushButton_deleteAruco_clicked(); break;
        case 10: _t->on_pushButton_SaveToImage_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject RobotDetectionMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RobotDetectionMainWindow.data,
      qt_meta_data_RobotDetectionMainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RobotDetectionMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotDetectionMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RobotDetectionMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RobotDetectionMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
