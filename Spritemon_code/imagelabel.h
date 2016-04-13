/*
 * SPRITEMON
 * A Sprite Pixel Editor
 *
 * University of Utah cs3505
 * 04/05/2016
 *
 * AUTHORS:
 *          Egan Anderson
 *          Jordan Davis
 *          Makenzie Elliott
 *          Jacob Osterloh
 *          Jen Simons
 *
*/

#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include "cmath"
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QMouseEvent>
#include <QColor>
#include <QString>
#include <QLinkedList>
#include <QPoint>
#include <QStack>
#include <QRgb>

class ImageLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ImageLabel(QWidget* parent = 0, QImage* image = new QImage(), int frameNumber = 0);
    ~ImageLabel();
    int sizeX;
    int sizeY;
    int frameNum;
    int numberOfPixels;
    int pixelWidth;
    int pixelNumber;
    int toolNumber;
    QColor color;
    QPixmap* pxmap;
    QImage* img;
    QImage* frame;

signals:
    void clicked();
    void updateCurrentFrameDisplay();
    void dropperColor(QColor);
    void updateModelWithNewFrame(QImage*);

public slots:
    void updatePixelNumber(int);
    void updateToolNumber(int);
    void updateFrameWidth(int);
    void updateCurrentColor(QColor);
    void updateCanvasToNewImage(QImage*);
    void detectCanvasButton(QString);
    void clearUndoRedoList(QImage*);

protected:
    QLinkedList<QImage *> undoList;
    QLinkedList<QImage *> redoList;
    void undo();
    void redo();
    void clearCanvas();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);
    void colorPixel(QMouseEvent* event);
    void colorLabelFromImage(QImage* image);
    void getPixelColor(QMouseEvent* event);
    void detectCanvasChange(QImage);
    void prepareForFill(QMouseEvent* event);
    void fillAdjacentColor(QPoint, QColor);
    void fillColor(QColor);
};

#endif

