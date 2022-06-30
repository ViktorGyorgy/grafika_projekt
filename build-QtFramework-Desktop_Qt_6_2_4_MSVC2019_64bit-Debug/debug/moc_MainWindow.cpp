/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QtFramework/GUI/MainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cagd__MainWindow_t {
    const uint offsetsAndSize[22];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cagd__MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cagd__MainWindow_t qt_meta_stringdata_cagd__MainWindow = {
    {
QT_MOC_LITERAL(0, 16), // "cagd::MainWindow"
QT_MOC_LITERAL(17, 24), // "on_action_Quit_triggered"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 12), // "setArcPointX"
QT_MOC_LITERAL(56, 12), // "setArcPointY"
QT_MOC_LITERAL(69, 12), // "setArcPointZ"
QT_MOC_LITERAL(82, 15), // "setNumberOfArcs"
QT_MOC_LITERAL(98, 14), // "setPatchPointX"
QT_MOC_LITERAL(113, 14), // "setPatchPointY"
QT_MOC_LITERAL(128, 14), // "setPatchPointZ"
QT_MOC_LITERAL(143, 18) // "setNumberOfPatches"

    },
    "cagd::MainWindow\0on_action_Quit_triggered\0"
    "\0setArcPointX\0setArcPointY\0setArcPointZ\0"
    "setNumberOfArcs\0setPatchPointX\0"
    "setPatchPointY\0setPatchPointZ\0"
    "setNumberOfPatches"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cagd__MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    1,   69,    2, 0x08,    2 /* Private */,
       4,    1,   72,    2, 0x08,    4 /* Private */,
       5,    1,   75,    2, 0x08,    6 /* Private */,
       6,    1,   78,    2, 0x08,    8 /* Private */,
       7,    1,   81,    2, 0x08,   10 /* Private */,
       8,    1,   84,    2, 0x08,   12 /* Private */,
       9,    1,   87,    2, 0x08,   14 /* Private */,
      10,    1,   90,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void cagd::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_action_Quit_triggered(); break;
        case 1: _t->setArcPointX((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->setArcPointY((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->setArcPointZ((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->setNumberOfArcs((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->setPatchPointX((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->setPatchPointY((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->setPatchPointZ((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->setNumberOfPatches((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject cagd::MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_cagd__MainWindow.offsetsAndSize,
    qt_meta_data_cagd__MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cagd__MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *cagd::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cagd::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cagd__MainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int cagd::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
