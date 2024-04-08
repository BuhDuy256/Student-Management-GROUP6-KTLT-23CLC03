/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../StudentManagementSystem/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_checkBox_stateChanged",
    "",
    "arg1",
    "on_button_signin_clicked",
    "on_txtUsername_textEdited",
    "on_txtPassword_textEdited",
    "on_button_exit_clicked",
    "on_button_StuSignOut_clicked",
    "on_button_AdSignOut_clicked",
    "on_button_StuChangePassword_clicked",
    "on_button_StuHome_clicked",
    "on_button_back_clicked",
    "on_stackedWidget_2_currentChanged",
    "on_button_confirm_clicked",
    "on_checkBox_2_stateChanged",
    "on_button_StuMyProfile_clicked",
    "on_button_StuMyCourses_clicked",
    "on_button_back_2_clicked",
    "on_stackedWidget_3_currentChanged",
    "on_button_AdMyProfile_clicked",
    "on_button_AdChangePassword_clicked",
    "on_button_AdHome_clicked",
    "on_button_confirm_2_clicked",
    "on_checkBox_3_stateChanged",
    "on_button_back_3_clicked",
    "on_button_back_4_clicked",
    "on_button_currentDay_clicked",
    "init_sy_select",
    "on_sy_select_currentTextChanged",
    "on_button_viewScore_clicked",
    "show_tableWidget_list",
    "show_tableWidget_score",
    "on_button_ok_clicked",
    "on_button_back_5_clicked",
    "on_button_create_sy_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[72];
    char stringdata0[11];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[25];
    char stringdata5[26];
    char stringdata6[26];
    char stringdata7[23];
    char stringdata8[29];
    char stringdata9[28];
    char stringdata10[36];
    char stringdata11[26];
    char stringdata12[23];
    char stringdata13[34];
    char stringdata14[26];
    char stringdata15[27];
    char stringdata16[31];
    char stringdata17[31];
    char stringdata18[25];
    char stringdata19[34];
    char stringdata20[30];
    char stringdata21[35];
    char stringdata22[25];
    char stringdata23[28];
    char stringdata24[27];
    char stringdata25[25];
    char stringdata26[25];
    char stringdata27[29];
    char stringdata28[15];
    char stringdata29[32];
    char stringdata30[28];
    char stringdata31[22];
    char stringdata32[23];
    char stringdata33[21];
    char stringdata34[25];
    char stringdata35[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 24),  // "on_checkBox_stateChanged"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 4),  // "arg1"
        QT_MOC_LITERAL(42, 24),  // "on_button_signin_clicked"
        QT_MOC_LITERAL(67, 25),  // "on_txtUsername_textEdited"
        QT_MOC_LITERAL(93, 25),  // "on_txtPassword_textEdited"
        QT_MOC_LITERAL(119, 22),  // "on_button_exit_clicked"
        QT_MOC_LITERAL(142, 28),  // "on_button_StuSignOut_clicked"
        QT_MOC_LITERAL(171, 27),  // "on_button_AdSignOut_clicked"
        QT_MOC_LITERAL(199, 35),  // "on_button_StuChangePassword_c..."
        QT_MOC_LITERAL(235, 25),  // "on_button_StuHome_clicked"
        QT_MOC_LITERAL(261, 22),  // "on_button_back_clicked"
        QT_MOC_LITERAL(284, 33),  // "on_stackedWidget_2_currentCha..."
        QT_MOC_LITERAL(318, 25),  // "on_button_confirm_clicked"
        QT_MOC_LITERAL(344, 26),  // "on_checkBox_2_stateChanged"
        QT_MOC_LITERAL(371, 30),  // "on_button_StuMyProfile_clicked"
        QT_MOC_LITERAL(402, 30),  // "on_button_StuMyCourses_clicked"
        QT_MOC_LITERAL(433, 24),  // "on_button_back_2_clicked"
        QT_MOC_LITERAL(458, 33),  // "on_stackedWidget_3_currentCha..."
        QT_MOC_LITERAL(492, 29),  // "on_button_AdMyProfile_clicked"
        QT_MOC_LITERAL(522, 34),  // "on_button_AdChangePassword_cl..."
        QT_MOC_LITERAL(557, 24),  // "on_button_AdHome_clicked"
        QT_MOC_LITERAL(582, 27),  // "on_button_confirm_2_clicked"
        QT_MOC_LITERAL(610, 26),  // "on_checkBox_3_stateChanged"
        QT_MOC_LITERAL(637, 24),  // "on_button_back_3_clicked"
        QT_MOC_LITERAL(662, 24),  // "on_button_back_4_clicked"
        QT_MOC_LITERAL(687, 28),  // "on_button_currentDay_clicked"
        QT_MOC_LITERAL(716, 14),  // "init_sy_select"
        QT_MOC_LITERAL(731, 31),  // "on_sy_select_currentTextChanged"
        QT_MOC_LITERAL(763, 27),  // "on_button_viewScore_clicked"
        QT_MOC_LITERAL(791, 21),  // "show_tableWidget_list"
        QT_MOC_LITERAL(813, 22),  // "show_tableWidget_score"
        QT_MOC_LITERAL(836, 20),  // "on_button_ok_clicked"
        QT_MOC_LITERAL(857, 24),  // "on_button_back_5_clicked"
        QT_MOC_LITERAL(882, 27)   // "on_button_create_sy_clicked"
    },
    "MainWindow",
    "on_checkBox_stateChanged",
    "",
    "arg1",
    "on_button_signin_clicked",
    "on_txtUsername_textEdited",
    "on_txtPassword_textEdited",
    "on_button_exit_clicked",
    "on_button_StuSignOut_clicked",
    "on_button_AdSignOut_clicked",
    "on_button_StuChangePassword_clicked",
    "on_button_StuHome_clicked",
    "on_button_back_clicked",
    "on_stackedWidget_2_currentChanged",
    "on_button_confirm_clicked",
    "on_checkBox_2_stateChanged",
    "on_button_StuMyProfile_clicked",
    "on_button_StuMyCourses_clicked",
    "on_button_back_2_clicked",
    "on_stackedWidget_3_currentChanged",
    "on_button_AdMyProfile_clicked",
    "on_button_AdChangePassword_clicked",
    "on_button_AdHome_clicked",
    "on_button_confirm_2_clicked",
    "on_checkBox_3_stateChanged",
    "on_button_back_3_clicked",
    "on_button_back_4_clicked",
    "on_button_currentDay_clicked",
    "init_sy_select",
    "on_sy_select_currentTextChanged",
    "on_button_viewScore_clicked",
    "show_tableWidget_list",
    "show_tableWidget_score",
    "on_button_ok_clicked",
    "on_button_back_5_clicked",
    "on_button_create_sy_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  212,    2, 0x08,    1 /* Private */,
       4,    0,  215,    2, 0x08,    3 /* Private */,
       5,    1,  216,    2, 0x08,    4 /* Private */,
       6,    1,  219,    2, 0x08,    6 /* Private */,
       7,    0,  222,    2, 0x08,    8 /* Private */,
       8,    0,  223,    2, 0x08,    9 /* Private */,
       9,    0,  224,    2, 0x08,   10 /* Private */,
      10,    0,  225,    2, 0x08,   11 /* Private */,
      11,    0,  226,    2, 0x08,   12 /* Private */,
      12,    0,  227,    2, 0x08,   13 /* Private */,
      13,    1,  228,    2, 0x08,   14 /* Private */,
      14,    0,  231,    2, 0x08,   16 /* Private */,
      15,    1,  232,    2, 0x08,   17 /* Private */,
      16,    0,  235,    2, 0x08,   19 /* Private */,
      17,    0,  236,    2, 0x08,   20 /* Private */,
      18,    0,  237,    2, 0x08,   21 /* Private */,
      19,    1,  238,    2, 0x08,   22 /* Private */,
      20,    0,  241,    2, 0x08,   24 /* Private */,
      21,    0,  242,    2, 0x08,   25 /* Private */,
      22,    0,  243,    2, 0x08,   26 /* Private */,
      23,    0,  244,    2, 0x08,   27 /* Private */,
      24,    1,  245,    2, 0x08,   28 /* Private */,
      25,    0,  248,    2, 0x08,   30 /* Private */,
      26,    0,  249,    2, 0x08,   31 /* Private */,
      27,    0,  250,    2, 0x08,   32 /* Private */,
      28,    0,  251,    2, 0x08,   33 /* Private */,
      29,    1,  252,    2, 0x08,   34 /* Private */,
      30,    0,  255,    2, 0x08,   36 /* Private */,
      31,    0,  256,    2, 0x08,   37 /* Private */,
      32,    0,  257,    2, 0x08,   38 /* Private */,
      33,    0,  258,    2, 0x08,   39 /* Private */,
      34,    0,  259,    2, 0x08,   40 /* Private */,
      35,    0,  260,    2, 0x08,   41 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_checkBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button_signin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_txtUsername_textEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_txtPassword_textEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_button_exit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_StuSignOut_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_AdSignOut_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_StuChangePassword_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_StuHome_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_back_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stackedWidget_2_currentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button_confirm_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_2_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button_StuMyProfile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_StuMyCourses_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_back_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stackedWidget_3_currentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button_AdMyProfile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_AdChangePassword_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_AdHome_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_confirm_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_3_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button_back_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_back_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_currentDay_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'init_sy_select'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sy_select_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_button_viewScore_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'show_tableWidget_list'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'show_tableWidget_score'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_ok_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_back_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_create_sy_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_button_signin_clicked(); break;
        case 2: _t->on_txtUsername_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_txtPassword_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_button_exit_clicked(); break;
        case 5: _t->on_button_StuSignOut_clicked(); break;
        case 6: _t->on_button_AdSignOut_clicked(); break;
        case 7: _t->on_button_StuChangePassword_clicked(); break;
        case 8: _t->on_button_StuHome_clicked(); break;
        case 9: _t->on_button_back_clicked(); break;
        case 10: _t->on_stackedWidget_2_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_button_confirm_clicked(); break;
        case 12: _t->on_checkBox_2_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_button_StuMyProfile_clicked(); break;
        case 14: _t->on_button_StuMyCourses_clicked(); break;
        case 15: _t->on_button_back_2_clicked(); break;
        case 16: _t->on_stackedWidget_3_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_button_AdMyProfile_clicked(); break;
        case 18: _t->on_button_AdChangePassword_clicked(); break;
        case 19: _t->on_button_AdHome_clicked(); break;
        case 20: _t->on_button_confirm_2_clicked(); break;
        case 21: _t->on_checkBox_3_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_button_back_3_clicked(); break;
        case 23: _t->on_button_back_4_clicked(); break;
        case 24: _t->on_button_currentDay_clicked(); break;
        case 25: _t->init_sy_select(); break;
        case 26: _t->on_sy_select_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 27: _t->on_button_viewScore_clicked(); break;
        case 28: _t->show_tableWidget_list(); break;
        case 29: _t->show_tableWidget_score(); break;
        case 30: _t->on_button_ok_clicked(); break;
        case 31: _t->on_button_back_5_clicked(); break;
        case 32: _t->on_button_create_sy_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 33;
    }
    return _id;
}
QT_WARNING_POP
