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

#include "mainwindow.h"
#include "spritemon.h"
#include "imagelabel.h"
#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Paint Frame
    QFrame *ptrPaintFrame = w.findChild<QFrame*>("paintFrame");
    ImageLabel iLabel( ptrPaintFrame, w.sprite.frames[0]);
    iLabel.setGeometry(0,50,448,448);
    iLabel.show();

    //set the initial size of the main window
    w.setGeometry(250,250,750,700);

    //Connections From View To Model
    QObject::connect(&w, SIGNAL(colorSelected(QColor)), &w.sprite, SLOT(updateRecentColorArray(QColor)));

    //Connections From View To iLabel
    QObject::connect(&w, SIGNAL(colorSelected(QColor)), &iLabel, SLOT(updateCurrentColor(QColor)));
    QObject::connect(&w, SIGNAL(pixelNumberSelected(int)), &iLabel, SLOT(updatePixelNumber(int)));
    QObject::connect(&w, SIGNAL(toolSelected(int)), &iLabel, SLOT(updateToolNumber(int)));
    QObject::connect(&w, SIGNAL(newFrameSelected(QImage*)), &iLabel, SLOT(updateCanvasToNewImage(QImage*)));
    QObject::connect(&w, SIGNAL(canvasButtonClicked(QString)), &iLabel, SLOT(detectCanvasButton(QString)));
    QObject::connect(&w, SIGNAL(newFrameSelected(QImage*)), &iLabel, SLOT(clearUndoRedoList(QImage*)));
    QObject::connect(&w, SIGNAL(setFrameSizeTo(int)), &iLabel, SLOT(updateFrameWidth(int)));

    //Connections From iLabel To View
    QObject::connect(&w.sprite, SIGNAL(previousColorArrayUpdated(QList<QColor>)), &w, SLOT(updateRecentColors(QList<QColor>)));
    QObject::connect(&iLabel, SIGNAL(dropperColor(QColor)), &w.sprite, SLOT(updateRecentColorArray(QColor)));
    QObject::connect(&iLabel, SIGNAL(dropperColor(QColor)), &iLabel, SLOT(updateCurrentColor(QColor)));
    QObject::connect(&iLabel, SIGNAL(updateCurrentFrameDisplay()), &w, SLOT(updateSelectedFrameDisplay()));
    QObject::connect(&iLabel, SIGNAL(updateModelWithNewFrame(QImage*)), &w, SLOT(updateSelectedFrameWithNewImage(QImage*)));

    w.show();
    w.askForFrameWidth();
    return a.exec();
}

