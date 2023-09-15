/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/QT_calc/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[379];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 6), // "signal"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 16), // "digits_functions"
QT_MOC_LITERAL(36, 14), // "digits_numbers"
QT_MOC_LITERAL(51, 14), // "digits_pov_mod"
QT_MOC_LITERAL(66, 25), // "on_pushButton_dot_clicked"
QT_MOC_LITERAL(92, 10), // "operations"
QT_MOC_LITERAL(103, 24), // "on_pushButton_eq_clicked"
QT_MOC_LITERAL(128, 27), // "on_pushButton_clear_clicked"
QT_MOC_LITERAL(156, 25), // "on_pushButton_del_clicked"
QT_MOC_LITERAL(182, 31), // "on_doubleSpinBox_x_valueChanged"
QT_MOC_LITERAL(214, 4), // "arg1"
QT_MOC_LITERAL(219, 26), // "on_pushButton_plus_clicked"
QT_MOC_LITERAL(246, 27), // "on_pushButton_minus_clicked"
QT_MOC_LITERAL(274, 26), // "on_pushButton_mult_clicked"
QT_MOC_LITERAL(301, 25), // "on_pushButton_div_clicked"
QT_MOC_LITERAL(327, 27), // "on_pushButton_graph_clicked"
QT_MOC_LITERAL(355, 23) // "on_pushButton_E_clicked"

    },
    "MainWindow\0signal\0\0digits_functions\0"
    "digits_numbers\0digits_pov_mod\0"
    "on_pushButton_dot_clicked\0operations\0"
    "on_pushButton_eq_clicked\0"
    "on_pushButton_clear_clicked\0"
    "on_pushButton_del_clicked\0"
    "on_doubleSpinBox_x_valueChanged\0arg1\0"
    "on_pushButton_plus_clicked\0"
    "on_pushButton_minus_clicked\0"
    "on_pushButton_mult_clicked\0"
    "on_pushButton_div_clicked\0"
    "on_pushButton_graph_clicked\0"
    "on_pushButton_E_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  111,    2, 0x08,    2 /* Private */,
       4,    0,  112,    2, 0x08,    3 /* Private */,
       5,    0,  113,    2, 0x08,    4 /* Private */,
       6,    0,  114,    2, 0x08,    5 /* Private */,
       7,    0,  115,    2, 0x08,    6 /* Private */,
       8,    0,  116,    2, 0x08,    7 /* Private */,
       9,    0,  117,    2, 0x08,    8 /* Private */,
      10,    0,  118,    2, 0x08,    9 /* Private */,
      11,    1,  119,    2, 0x08,   10 /* Private */,
      13,    0,  122,    2, 0x08,   12 /* Private */,
      14,    0,  123,    2, 0x08,   13 /* Private */,
      15,    0,  124,    2, 0x08,   14 /* Private */,
      16,    0,  125,    2, 0x08,   15 /* Private */,
      17,    0,  126,    2, 0x08,   16 /* Private */,
      18,    0,  127,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal(); break;
        case 1: _t->digits_functions(); break;
        case 2: _t->digits_numbers(); break;
        case 3: _t->digits_pov_mod(); break;
        case 4: _t->on_pushButton_dot_clicked(); break;
        case 5: _t->operations(); break;
        case 6: _t->on_pushButton_eq_clicked(); break;
        case 7: _t->on_pushButton_clear_clicked(); break;
        case 8: _t->on_pushButton_del_clicked(); break;
        case 9: _t->on_doubleSpinBox_x_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_plus_clicked(); break;
        case 11: _t->on_pushButton_minus_clicked(); break;
        case 12: _t->on_pushButton_mult_clicked(); break;
        case 13: _t->on_pushButton_div_clicked(); break;
        case 14: _t->on_pushButton_graph_clicked(); break;
        case 15: _t->on_pushButton_E_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
