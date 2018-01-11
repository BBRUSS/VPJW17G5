/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[377];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "frameReady"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 28), // "on_startCameraButton_clicked"
QT_MOC_LITERAL(4, 52, 27), // "on_stopCameraButton_clicked"
QT_MOC_LITERAL(5, 80, 17), // "cameraCalibration"
QT_MOC_LITERAL(6, 98, 11), // "vector<Mat>"
QT_MOC_LITERAL(7, 110, 17), // "calibrationImages"
QT_MOC_LITERAL(8, 128, 4), // "Size"
QT_MOC_LITERAL(9, 133, 9), // "boardSize"
QT_MOC_LITERAL(10, 143, 16), // "squareEdgeLength"
QT_MOC_LITERAL(11, 160, 4), // "Mat&"
QT_MOC_LITERAL(12, 165, 12), // "cameraMatrix"
QT_MOC_LITERAL(13, 178, 20), // "distanceCoefficients"
QT_MOC_LITERAL(14, 199, 24), // "createKnownBoardPosition"
QT_MOC_LITERAL(15, 224, 8), // "cv::Size"
QT_MOC_LITERAL(16, 233, 16), // "vector<Point3f>&"
QT_MOC_LITERAL(17, 250, 7), // "corners"
QT_MOC_LITERAL(18, 258, 20), // "getChessboardCorners"
QT_MOC_LITERAL(19, 279, 6), // "images"
QT_MOC_LITERAL(20, 286, 25), // "vector<vector<Point2f> >&"
QT_MOC_LITERAL(21, 312, 15), // "allFoundCorners"
QT_MOC_LITERAL(22, 328, 10), // "showResult"
QT_MOC_LITERAL(23, 339, 21), // "saveCameraCalibration"
QT_MOC_LITERAL(24, 361, 6), // "string"
QT_MOC_LITERAL(25, 368, 4), // "name"
QT_MOC_LITERAL(26, 373, 3) // "Mat"

    },
    "MainWindow\0frameReady\0\0"
    "on_startCameraButton_clicked\0"
    "on_stopCameraButton_clicked\0"
    "cameraCalibration\0vector<Mat>\0"
    "calibrationImages\0Size\0boardSize\0"
    "squareEdgeLength\0Mat&\0cameraMatrix\0"
    "distanceCoefficients\0createKnownBoardPosition\0"
    "cv::Size\0vector<Point3f>&\0corners\0"
    "getChessboardCorners\0images\0"
    "vector<vector<Point2f> >&\0allFoundCorners\0"
    "showResult\0saveCameraCalibration\0"
    "string\0name\0Mat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    5,   52,    2, 0x08 /* Private */,
      14,    3,   63,    2, 0x08 /* Private */,
      18,    3,   70,    2, 0x08 /* Private */,
      23,    3,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, QMetaType::Float, 0x80000000 | 11, 0x80000000 | 11,    7,    9,   10,   12,   13,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Float, 0x80000000 | 16,    9,   10,   17,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 20, QMetaType::Bool,   19,   21,   22,
    QMetaType::Bool, 0x80000000 | 24, 0x80000000 | 26, 0x80000000 | 26,   25,   12,   13,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameReady(); break;
        case 1: _t->on_startCameraButton_clicked(); break;
        case 2: _t->on_stopCameraButton_clicked(); break;
        case 3: _t->cameraCalibration((*reinterpret_cast< vector<Mat>(*)>(_a[1])),(*reinterpret_cast< Size(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< Mat(*)>(_a[4])),(*reinterpret_cast< Mat(*)>(_a[5]))); break;
        case 4: _t->createKnownBoardPosition((*reinterpret_cast< cv::Size(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< vector<Point3f>(*)>(_a[3]))); break;
        case 5: _t->getChessboardCorners((*reinterpret_cast< vector<Mat>(*)>(_a[1])),(*reinterpret_cast< vector<vector<Point2f> >(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: { bool _r = _t->saveCameraCalibration((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< Mat(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
