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
    QByteArrayData data[46];
    char stringdata0[917];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotDetectionMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotDetectionMainWindow_t qt_meta_stringdata_RobotDetectionMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 24), // "RobotDetectionMainWindow"
QT_MOC_LITERAL(1, 25, 10), // "stopWorker"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 20), // "workerUpdateSettings"
QT_MOC_LITERAL(4, 58, 13), // "taskThreshold"
QT_MOC_LITERAL(5, 72, 15), // "taskRectMinSize"
QT_MOC_LITERAL(6, 88, 10), // "robotCount"
QT_MOC_LITERAL(7, 99, 9), // "debugMode"
QT_MOC_LITERAL(8, 109, 11), // "measureData"
QT_MOC_LITERAL(9, 121, 38), // "cv::Ptr<cv::aruco::DetectorPa..."
QT_MOC_LITERAL(10, 160, 15), // "arucoParameters"
QT_MOC_LITERAL(11, 176, 30), // "cv::Ptr<cv::aruco::Dictionary>"
QT_MOC_LITERAL(12, 207, 9), // "arucoDict"
QT_MOC_LITERAL(13, 217, 18), // "QList<RobotOffset>"
QT_MOC_LITERAL(14, 236, 12), // "robotOffsets"
QT_MOC_LITERAL(15, 249, 22), // "calibrateOffset_ON_OFF"
QT_MOC_LITERAL(16, 272, 19), // "incrementFPSCounter"
QT_MOC_LITERAL(17, 292, 19), // "incrementUDPCounter"
QT_MOC_LITERAL(18, 312, 18), // "updateRobotOffsets"
QT_MOC_LITERAL(19, 331, 12), // "foundOffsets"
QT_MOC_LITERAL(20, 344, 30), // "on_pushButton_addAruco_clicked"
QT_MOC_LITERAL(21, 375, 33), // "on_pushButton_deleteAruco_cli..."
QT_MOC_LITERAL(22, 409, 33), // "on_pushButton_SaveToImage_cli..."
QT_MOC_LITERAL(23, 443, 36), // "on_pushButtonCalibrateOffset_..."
QT_MOC_LITERAL(24, 480, 30), // "on_pushButtonStartStop_clicked"
QT_MOC_LITERAL(25, 511, 32), // "on_tableWidget_Aruco_cellChanged"
QT_MOC_LITERAL(26, 544, 3), // "row"
QT_MOC_LITERAL(27, 548, 6), // "column"
QT_MOC_LITERAL(28, 555, 32), // "on_tableWidget_Aruco_cellClicked"
QT_MOC_LITERAL(29, 588, 24), // "on_tabMain_tabBarClicked"
QT_MOC_LITERAL(30, 613, 5), // "index"
QT_MOC_LITERAL(31, 619, 11), // "updateFrame"
QT_MOC_LITERAL(32, 631, 27), // "on_pushButtonChange_clicked"
QT_MOC_LITERAL(33, 659, 35), // "on_pushButtonResizeCamField_c..."
QT_MOC_LITERAL(34, 695, 33), // "on_pushButtonSaveSettings_cli..."
QT_MOC_LITERAL(35, 729, 14), // "updateGuiImage"
QT_MOC_LITERAL(36, 744, 14), // "QList<cv::Mat>"
QT_MOC_LITERAL(37, 759, 11), // "cameraImage"
QT_MOC_LITERAL(38, 771, 18), // "QList<cv::Point3f>"
QT_MOC_LITERAL(39, 790, 14), // "robotLocations"
QT_MOC_LITERAL(40, 805, 10), // "QList<int>"
QT_MOC_LITERAL(41, 816, 19), // "robotLocationsStd1d"
QT_MOC_LITERAL(42, 836, 28), // "QList<QList<RobotPosition> >"
QT_MOC_LITERAL(43, 865, 15), // "robotIDLocation"
QT_MOC_LITERAL(44, 881, 20), // "QList<RobotPosition>"
QT_MOC_LITERAL(45, 902, 14) // "detectedRobots"

    },
    "RobotDetectionMainWindow\0stopWorker\0"
    "\0workerUpdateSettings\0taskThreshold\0"
    "taskRectMinSize\0robotCount\0debugMode\0"
    "measureData\0cv::Ptr<cv::aruco::DetectorParameters>\0"
    "arucoParameters\0cv::Ptr<cv::aruco::Dictionary>\0"
    "arucoDict\0QList<RobotOffset>\0robotOffsets\0"
    "calibrateOffset_ON_OFF\0incrementFPSCounter\0"
    "incrementUDPCounter\0updateRobotOffsets\0"
    "foundOffsets\0on_pushButton_addAruco_clicked\0"
    "on_pushButton_deleteAruco_clicked\0"
    "on_pushButton_SaveToImage_clicked\0"
    "on_pushButtonCalibrateOffset_clicked\0"
    "on_pushButtonStartStop_clicked\0"
    "on_tableWidget_Aruco_cellChanged\0row\0"
    "column\0on_tableWidget_Aruco_cellClicked\0"
    "on_tabMain_tabBarClicked\0index\0"
    "updateFrame\0on_pushButtonChange_clicked\0"
    "on_pushButtonResizeCamField_clicked\0"
    "on_pushButtonSaveSettings_clicked\0"
    "updateGuiImage\0QList<cv::Mat>\0cameraImage\0"
    "QList<cv::Point3f>\0robotLocations\0"
    "QList<int>\0robotLocationsStd1d\0"
    "QList<QList<RobotPosition> >\0"
    "robotIDLocation\0QList<RobotPosition>\0"
    "detectedRobots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotDetectionMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    9,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  124,    2, 0x08 /* Private */,
      17,    0,  125,    2, 0x08 /* Private */,
      18,    1,  126,    2, 0x08 /* Private */,
      20,    0,  129,    2, 0x08 /* Private */,
      21,    0,  130,    2, 0x08 /* Private */,
      22,    0,  131,    2, 0x08 /* Private */,
      23,    0,  132,    2, 0x08 /* Private */,
      24,    0,  133,    2, 0x08 /* Private */,
      25,    2,  134,    2, 0x08 /* Private */,
      28,    2,  139,    2, 0x08 /* Private */,
      29,    1,  144,    2, 0x08 /* Private */,
      31,    0,  147,    2, 0x08 /* Private */,
      32,    0,  148,    2, 0x08 /* Private */,
      33,    0,  149,    2, 0x08 /* Private */,
      34,    0,  150,    2, 0x08 /* Private */,
      35,    5,  151,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 9, 0x80000000 | 11, 0x80000000 | 13, QMetaType::Bool,    4,    5,    6,    7,    8,   10,   12,   14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   26,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   26,   27,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 36, 0x80000000 | 38, 0x80000000 | 40, 0x80000000 | 42, 0x80000000 | 44,   37,   39,   41,   43,   45,

       0        // eod
};

void RobotDetectionMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotDetectionMainWindow *_t = static_cast<RobotDetectionMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopWorker(); break;
        case 1: _t->workerUpdateSettings((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< cv::Ptr<cv::aruco::DetectorParameters>(*)>(_a[6])),(*reinterpret_cast< cv::Ptr<cv::aruco::Dictionary>(*)>(_a[7])),(*reinterpret_cast< QList<RobotOffset>(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9]))); break;
        case 2: _t->incrementFPSCounter(); break;
        case 3: _t->incrementUDPCounter(); break;
        case 4: _t->updateRobotOffsets((*reinterpret_cast< QList<RobotOffset>(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_addAruco_clicked(); break;
        case 6: _t->on_pushButton_deleteAruco_clicked(); break;
        case 7: _t->on_pushButton_SaveToImage_clicked(); break;
        case 8: _t->on_pushButtonCalibrateOffset_clicked(); break;
        case 9: _t->on_pushButtonStartStop_clicked(); break;
        case 10: _t->on_tableWidget_Aruco_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_tableWidget_Aruco_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->on_tabMain_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->updateFrame(); break;
        case 14: _t->on_pushButtonChange_clicked(); break;
        case 15: _t->on_pushButtonResizeCamField_clicked(); break;
        case 16: _t->on_pushButtonSaveSettings_clicked(); break;
        case 17: _t->updateGuiImage((*reinterpret_cast< const QList<cv::Mat>(*)>(_a[1])),(*reinterpret_cast< const QList<cv::Point3f>(*)>(_a[2])),(*reinterpret_cast< const QList<int>(*)>(_a[3])),(*reinterpret_cast< const QList<QList<RobotPosition> >(*)>(_a[4])),(*reinterpret_cast< const QList<RobotPosition>(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 17:
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
            typedef void (RobotDetectionMainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDetectionMainWindow::stopWorker)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RobotDetectionMainWindow::*_t)(int , int , int , bool , bool , cv::Ptr<cv::aruco::DetectorParameters> , cv::Ptr<cv::aruco::Dictionary> , QList<RobotOffset> , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDetectionMainWindow::workerUpdateSettings)) {
                *result = 1;
                return;
            }
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void RobotDetectionMainWindow::stopWorker()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RobotDetectionMainWindow::workerUpdateSettings(int _t1, int _t2, int _t3, bool _t4, bool _t5, cv::Ptr<cv::aruco::DetectorParameters> _t6, cv::Ptr<cv::aruco::Dictionary> _t7, QList<RobotOffset> _t8, bool _t9)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
