/****************************************************************************
** Meta object code from reading C++ file 'cameracontrast.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cameracontrast.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameracontrast.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CameraContrast_t {
    QByteArrayData data[12];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraContrast_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraContrast_t qt_meta_stringdata_CameraContrast = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CameraContrast"
QT_MOC_LITERAL(1, 15, 10), // "frameReady"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 29), // "on_pushButtonStartCam_clicked"
QT_MOC_LITERAL(4, 57, 28), // "on_pushButtonStopCam_clicked"
QT_MOC_LITERAL(5, 86, 33), // "on_pushButtonSaveContrast_cli..."
QT_MOC_LITERAL(6, 120, 34), // "on_pushButtonGetIntrinsics_cl..."
QT_MOC_LITERAL(7, 155, 34), // "on_pushButtonGetExtrinsics_cl..."
QT_MOC_LITERAL(8, 190, 29), // "on_pushButtonResetThr_clicked"
QT_MOC_LITERAL(9, 220, 37), // "on_pushButtonCloseCalibWindow..."
QT_MOC_LITERAL(10, 258, 39), // "on_checkBoxInvertGrayscale_st..."
QT_MOC_LITERAL(11, 298, 4) // "arg1"

    },
    "CameraContrast\0frameReady\0\0"
    "on_pushButtonStartCam_clicked\0"
    "on_pushButtonStopCam_clicked\0"
    "on_pushButtonSaveContrast_clicked\0"
    "on_pushButtonGetIntrinsics_clicked\0"
    "on_pushButtonGetExtrinsics_clicked\0"
    "on_pushButtonResetThr_clicked\0"
    "on_pushButtonCloseCalibWindow_clicked\0"
    "on_checkBoxInvertGrayscale_stateChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraContrast[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void CameraContrast::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraContrast *_t = static_cast<CameraContrast *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameReady(); break;
        case 1: _t->on_pushButtonStartCam_clicked(); break;
        case 2: _t->on_pushButtonStopCam_clicked(); break;
        case 3: _t->on_pushButtonSaveContrast_clicked(); break;
        case 4: _t->on_pushButtonGetIntrinsics_clicked(); break;
        case 5: _t->on_pushButtonGetExtrinsics_clicked(); break;
        case 6: _t->on_pushButtonResetThr_clicked(); break;
        case 7: _t->on_pushButtonCloseCalibWindow_clicked(); break;
        case 8: _t->on_checkBoxInvertGrayscale_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CameraContrast::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CameraContrast.data,
      qt_meta_data_CameraContrast,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CameraContrast::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraContrast::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CameraContrast.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CameraContrast::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
