/****************************************************************************
** Meta object code from reading C++ file 'imagelabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SpritemonCode/imagelabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagelabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageLabel_t {
    QByteArrayData data[14];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageLabel_t qt_meta_stringdata_ImageLabel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ImageLabel"
QT_MOC_LITERAL(1, 11, 7), // "clicked"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 25), // "updateCurrentFrameDisplay"
QT_MOC_LITERAL(4, 46, 12), // "dropperColor"
QT_MOC_LITERAL(5, 59, 23), // "updateModelWithNewFrame"
QT_MOC_LITERAL(6, 83, 7), // "QImage*"
QT_MOC_LITERAL(7, 91, 17), // "updatePixelNumber"
QT_MOC_LITERAL(8, 109, 16), // "updateToolNumber"
QT_MOC_LITERAL(9, 126, 16), // "updateFrameWidth"
QT_MOC_LITERAL(10, 143, 18), // "updateCurrentColor"
QT_MOC_LITERAL(11, 162, 22), // "updateCanvasToNewImage"
QT_MOC_LITERAL(12, 185, 18), // "detectCanvasButton"
QT_MOC_LITERAL(13, 204, 17) // "clearUndoRedoList"

    },
    "ImageLabel\0clicked\0\0updateCurrentFrameDisplay\0"
    "dropperColor\0updateModelWithNewFrame\0"
    "QImage*\0updatePixelNumber\0updateToolNumber\0"
    "updateFrameWidth\0updateCurrentColor\0"
    "updateCanvasToNewImage\0detectCanvasButton\0"
    "clearUndoRedoList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    1,   71,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   77,    2, 0x0a /* Public */,
       8,    1,   80,    2, 0x0a /* Public */,
       9,    1,   83,    2, 0x0a /* Public */,
      10,    1,   86,    2, 0x0a /* Public */,
      11,    1,   89,    2, 0x0a /* Public */,
      12,    1,   92,    2, 0x0a /* Public */,
      13,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void ImageLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageLabel *_t = static_cast<ImageLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->updateCurrentFrameDisplay(); break;
        case 2: _t->dropperColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->updateModelWithNewFrame((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 4: _t->updatePixelNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateToolNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateFrameWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateCurrentColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 8: _t->updateCanvasToNewImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 9: _t->detectCanvasButton((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->clearUndoRedoList((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageLabel::clicked)) {
                *result = 0;
            }
        }
        {
            typedef void (ImageLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageLabel::updateCurrentFrameDisplay)) {
                *result = 1;
            }
        }
        {
            typedef void (ImageLabel::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageLabel::dropperColor)) {
                *result = 2;
            }
        }
        {
            typedef void (ImageLabel::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageLabel::updateModelWithNewFrame)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ImageLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_ImageLabel.data,
      qt_meta_data_ImageLabel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageLabel.stringdata0))
        return static_cast<void*>(const_cast< ImageLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int ImageLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ImageLabel::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ImageLabel::updateCurrentFrameDisplay()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ImageLabel::dropperColor(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImageLabel::updateModelWithNewFrame(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
