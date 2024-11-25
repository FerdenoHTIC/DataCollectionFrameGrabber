/****************************************************************************
** Meta object code from reading C++ file 'videorecorder.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../videorecorder.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videorecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSVideoRecorderENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSVideoRecorderENDCLASS = QtMocHelpers::stringData(
    "VideoRecorder",
    "on_startCamera_clicked",
    "",
    "on_stopCamera_clicked",
    "on_Head_clicked",
    "on_Face_clicked",
    "on_Abdomen_clicked",
    "on_Pelvis_clicked",
    "on_Thorax_clicked",
    "on_Spine_clicked",
    "on_Upper_Extremities_clicked",
    "on_Lower_Extremities_clicked",
    "on_General_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVideoRecorderENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject VideoRecorder::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSVideoRecorderENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVideoRecorderENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVideoRecorderENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VideoRecorder, std::true_type>,
        // method 'on_startCamera_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stopCamera_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Head_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Face_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Abdomen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pelvis_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Thorax_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Spine_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Upper_Extremities_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Lower_Extremities_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_General_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void VideoRecorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoRecorder *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_startCamera_clicked(); break;
        case 1: _t->on_stopCamera_clicked(); break;
        case 2: _t->on_Head_clicked(); break;
        case 3: _t->on_Face_clicked(); break;
        case 4: _t->on_Abdomen_clicked(); break;
        case 5: _t->on_Pelvis_clicked(); break;
        case 6: _t->on_Thorax_clicked(); break;
        case 7: _t->on_Spine_clicked(); break;
        case 8: _t->on_Upper_Extremities_clicked(); break;
        case 9: _t->on_Lower_Extremities_clicked(); break;
        case 10: _t->on_General_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *VideoRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVideoRecorderENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VideoRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
