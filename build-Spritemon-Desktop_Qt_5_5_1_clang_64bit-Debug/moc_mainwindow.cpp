/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SpritemonCode/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[56];
    char stringdata0[1409];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "colorSelected"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 19), // "pixelNumberSelected"
QT_MOC_LITERAL(4, 46, 12), // "toolSelected"
QT_MOC_LITERAL(5, 59, 16), // "newFrameSelected"
QT_MOC_LITERAL(6, 76, 7), // "QImage*"
QT_MOC_LITERAL(7, 84, 19), // "canvasButtonClicked"
QT_MOC_LITERAL(8, 104, 14), // "setFrameSizeTo"
QT_MOC_LITERAL(9, 119, 18), // "updateRecentColors"
QT_MOC_LITERAL(10, 138, 13), // "QList<QColor>"
QT_MOC_LITERAL(11, 152, 26), // "updateSelectedFrameDisplay"
QT_MOC_LITERAL(12, 179, 31), // "updateSelectedFrameWithNewImage"
QT_MOC_LITERAL(13, 211, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(14, 235, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(15, 262, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(16, 286, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(17, 310, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(18, 334, 30), // "on_actionClear_Frame_triggered"
QT_MOC_LITERAL(19, 365, 28), // "on_actionNew_Frame_triggered"
QT_MOC_LITERAL(20, 394, 34), // "on_actionDuplicate_Frame_trig..."
QT_MOC_LITERAL(21, 429, 31), // "on_actionDelete_Frame_triggered"
QT_MOC_LITERAL(22, 461, 24), // "on_actionColor_triggered"
QT_MOC_LITERAL(23, 486, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(24, 511, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(25, 534, 29), // "previewAnimationTimerFinished"
QT_MOC_LITERAL(26, 564, 32), // "on_colorPalletToolButton_pressed"
QT_MOC_LITERAL(27, 597, 29), // "on_currentColorButton_clicked"
QT_MOC_LITERAL(28, 627, 31), // "on_previousColor1Button_pressed"
QT_MOC_LITERAL(29, 659, 31), // "on_previousColor2Button_pressed"
QT_MOC_LITERAL(30, 691, 31), // "on_previousColor3Button_pressed"
QT_MOC_LITERAL(31, 723, 31), // "on_previousColor4Button_pressed"
QT_MOC_LITERAL(32, 755, 31), // "on_previousColor5Button_pressed"
QT_MOC_LITERAL(33, 787, 31), // "on_previousColor6Button_pressed"
QT_MOC_LITERAL(34, 819, 28), // "on_deleteFrameButton_clicked"
QT_MOC_LITERAL(35, 848, 31), // "on_framesListWidget_itemPressed"
QT_MOC_LITERAL(36, 880, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(37, 897, 4), // "item"
QT_MOC_LITERAL(38, 902, 31), // "on_largePixelToolButton_clicked"
QT_MOC_LITERAL(39, 934, 32), // "on_mediumPixelToolButton_clicked"
QT_MOC_LITERAL(40, 967, 31), // "on_smallPixelToolButton_clicked"
QT_MOC_LITERAL(41, 999, 31), // "on_paintbrushToolButton_clicked"
QT_MOC_LITERAL(42, 1031, 26), // "on_eraseToolButton_clicked"
QT_MOC_LITERAL(43, 1058, 32), // "on_paintbucketToolButton_clicked"
QT_MOC_LITERAL(44, 1091, 27), // "on_mirrorToolButton_clicked"
QT_MOC_LITERAL(45, 1119, 25), // "on_flipToolButton_clicked"
QT_MOC_LITERAL(46, 1145, 27), // "on_darkenToolButton_clicked"
QT_MOC_LITERAL(47, 1173, 28), // "on_lightenToolButton_clicked"
QT_MOC_LITERAL(48, 1202, 29), // "on_colorDropperButton_clicked"
QT_MOC_LITERAL(49, 1232, 28), // "on_pencileToolButton_clicked"
QT_MOC_LITERAL(50, 1261, 22), // "on_clearButton_clicked"
QT_MOC_LITERAL(51, 1284, 21), // "on_undoButton_clicked"
QT_MOC_LITERAL(52, 1306, 21), // "on_redoButton_clicked"
QT_MOC_LITERAL(53, 1328, 31), // "on_duplicateFrameButton_pressed"
QT_MOC_LITERAL(54, 1360, 24), // "on_enlargeButton_clicked"
QT_MOC_LITERAL(55, 1385, 23) // "on_actualButton_clicked"

    },
    "MainWindow\0colorSelected\0\0pixelNumberSelected\0"
    "toolSelected\0newFrameSelected\0QImage*\0"
    "canvasButtonClicked\0setFrameSizeTo\0"
    "updateRecentColors\0QList<QColor>\0"
    "updateSelectedFrameDisplay\0"
    "updateSelectedFrameWithNewImage\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionOpen_triggered\0on_actionUndo_triggered\0"
    "on_actionRedo_triggered\0"
    "on_actionClear_Frame_triggered\0"
    "on_actionNew_Frame_triggered\0"
    "on_actionDuplicate_Frame_triggered\0"
    "on_actionDelete_Frame_triggered\0"
    "on_actionColor_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionNew_triggered\0"
    "previewAnimationTimerFinished\0"
    "on_colorPalletToolButton_pressed\0"
    "on_currentColorButton_clicked\0"
    "on_previousColor1Button_pressed\0"
    "on_previousColor2Button_pressed\0"
    "on_previousColor3Button_pressed\0"
    "on_previousColor4Button_pressed\0"
    "on_previousColor5Button_pressed\0"
    "on_previousColor6Button_pressed\0"
    "on_deleteFrameButton_clicked\0"
    "on_framesListWidget_itemPressed\0"
    "QListWidgetItem*\0item\0"
    "on_largePixelToolButton_clicked\0"
    "on_mediumPixelToolButton_clicked\0"
    "on_smallPixelToolButton_clicked\0"
    "on_paintbrushToolButton_clicked\0"
    "on_eraseToolButton_clicked\0"
    "on_paintbucketToolButton_clicked\0"
    "on_mirrorToolButton_clicked\0"
    "on_flipToolButton_clicked\0"
    "on_darkenToolButton_clicked\0"
    "on_lightenToolButton_clicked\0"
    "on_colorDropperButton_clicked\0"
    "on_pencileToolButton_clicked\0"
    "on_clearButton_clicked\0on_undoButton_clicked\0"
    "on_redoButton_clicked\0"
    "on_duplicateFrameButton_pressed\0"
    "on_enlargeButton_clicked\0"
    "on_actualButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  264,    2, 0x06 /* Public */,
       3,    1,  267,    2, 0x06 /* Public */,
       4,    1,  270,    2, 0x06 /* Public */,
       5,    1,  273,    2, 0x06 /* Public */,
       7,    1,  276,    2, 0x06 /* Public */,
       8,    1,  279,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  282,    2, 0x0a /* Public */,
      11,    0,  285,    2, 0x0a /* Public */,
      12,    1,  286,    2, 0x0a /* Public */,
      13,    0,  289,    2, 0x0a /* Public */,
      14,    0,  290,    2, 0x0a /* Public */,
      15,    0,  291,    2, 0x0a /* Public */,
      16,    0,  292,    2, 0x0a /* Public */,
      17,    0,  293,    2, 0x0a /* Public */,
      18,    0,  294,    2, 0x0a /* Public */,
      19,    0,  295,    2, 0x0a /* Public */,
      20,    0,  296,    2, 0x0a /* Public */,
      21,    0,  297,    2, 0x0a /* Public */,
      22,    0,  298,    2, 0x0a /* Public */,
      23,    0,  299,    2, 0x0a /* Public */,
      24,    0,  300,    2, 0x0a /* Public */,
      25,    0,  301,    2, 0x08 /* Private */,
      26,    0,  302,    2, 0x08 /* Private */,
      27,    0,  303,    2, 0x08 /* Private */,
      28,    0,  304,    2, 0x08 /* Private */,
      29,    0,  305,    2, 0x08 /* Private */,
      30,    0,  306,    2, 0x08 /* Private */,
      31,    0,  307,    2, 0x08 /* Private */,
      32,    0,  308,    2, 0x08 /* Private */,
      33,    0,  309,    2, 0x08 /* Private */,
      34,    0,  310,    2, 0x08 /* Private */,
      35,    1,  311,    2, 0x08 /* Private */,
      38,    0,  314,    2, 0x08 /* Private */,
      39,    0,  315,    2, 0x08 /* Private */,
      40,    0,  316,    2, 0x08 /* Private */,
      41,    0,  317,    2, 0x08 /* Private */,
      42,    0,  318,    2, 0x08 /* Private */,
      43,    0,  319,    2, 0x08 /* Private */,
      44,    0,  320,    2, 0x08 /* Private */,
      45,    0,  321,    2, 0x08 /* Private */,
      46,    0,  322,    2, 0x08 /* Private */,
      47,    0,  323,    2, 0x08 /* Private */,
      48,    0,  324,    2, 0x08 /* Private */,
      49,    0,  325,    2, 0x08 /* Private */,
      50,    0,  326,    2, 0x08 /* Private */,
      51,    0,  327,    2, 0x08 /* Private */,
      52,    0,  328,    2, 0x08 /* Private */,
      53,    0,  329,    2, 0x08 /* Private */,
      54,    0,  330,    2, 0x08 /* Private */,
      55,    0,  331,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
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
    QMetaType::Void, 0x80000000 | 36,   37,
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
    QMetaType::Void,
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
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->colorSelected((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->pixelNumberSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->toolSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->newFrameSelected((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 4: _t->canvasButtonClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setFrameSizeTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateRecentColors((*reinterpret_cast< QList<QColor>(*)>(_a[1]))); break;
        case 7: _t->updateSelectedFrameDisplay(); break;
        case 8: _t->updateSelectedFrameWithNewImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 9: _t->on_actionSave_triggered(); break;
        case 10: _t->on_actionSave_As_triggered(); break;
        case 11: _t->on_actionOpen_triggered(); break;
        case 12: _t->on_actionUndo_triggered(); break;
        case 13: _t->on_actionRedo_triggered(); break;
        case 14: _t->on_actionClear_Frame_triggered(); break;
        case 15: _t->on_actionNew_Frame_triggered(); break;
        case 16: _t->on_actionDuplicate_Frame_triggered(); break;
        case 17: _t->on_actionDelete_Frame_triggered(); break;
        case 18: _t->on_actionColor_triggered(); break;
        case 19: _t->on_actionClose_triggered(); break;
        case 20: _t->on_actionNew_triggered(); break;
        case 21: _t->previewAnimationTimerFinished(); break;
        case 22: _t->on_colorPalletToolButton_pressed(); break;
        case 23: _t->on_currentColorButton_clicked(); break;
        case 24: _t->on_previousColor1Button_pressed(); break;
        case 25: _t->on_previousColor2Button_pressed(); break;
        case 26: _t->on_previousColor3Button_pressed(); break;
        case 27: _t->on_previousColor4Button_pressed(); break;
        case 28: _t->on_previousColor5Button_pressed(); break;
        case 29: _t->on_previousColor6Button_pressed(); break;
        case 30: _t->on_deleteFrameButton_clicked(); break;
        case 31: _t->on_framesListWidget_itemPressed((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 32: _t->on_largePixelToolButton_clicked(); break;
        case 33: _t->on_mediumPixelToolButton_clicked(); break;
        case 34: _t->on_smallPixelToolButton_clicked(); break;
        case 35: _t->on_paintbrushToolButton_clicked(); break;
        case 36: _t->on_eraseToolButton_clicked(); break;
        case 37: _t->on_paintbucketToolButton_clicked(); break;
        case 38: _t->on_mirrorToolButton_clicked(); break;
        case 39: _t->on_flipToolButton_clicked(); break;
        case 40: _t->on_darkenToolButton_clicked(); break;
        case 41: _t->on_lightenToolButton_clicked(); break;
        case 42: _t->on_colorDropperButton_clicked(); break;
        case 43: _t->on_pencileToolButton_clicked(); break;
        case 44: _t->on_clearButton_clicked(); break;
        case 45: _t->on_undoButton_clicked(); break;
        case 46: _t->on_redoButton_clicked(); break;
        case 47: _t->on_duplicateFrameButton_pressed(); break;
        case 48: _t->on_enlargeButton_clicked(); break;
        case 49: _t->on_actualButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QColor> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::colorSelected)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::pixelNumberSelected)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::toolSelected)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::newFrameSelected)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::canvasButtonClicked)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::setFrameSizeTo)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::colorSelected(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::pixelNumberSelected(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::toolSelected(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::newFrameSelected(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::canvasButtonClicked(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::setFrameSizeTo(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
