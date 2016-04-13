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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "spritemon.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QColor>
#include <QList>
#include <QListWidgetItem>
#include <QMouseEvent>
#include <QString>
#include <QTimer>
#include <QTextStream>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Spritemon sprite;
    void askForFrameWidth();

signals:
    void colorSelected(QColor);
    void pixelNumberSelected(int);
    void toolSelected(int);
    void newFrameSelected(QImage*);
    void canvasButtonClicked(QString);
    void setFrameSizeTo(int);

public slots:
    void updateRecentColors(QList<QColor>);
    void updateSelectedFrameDisplay();
    void updateSelectedFrameWithNewImage(QImage*);
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionOpen_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionClear_Frame_triggered();
    void on_actionNew_Frame_triggered();
    void on_actionDuplicate_Frame_triggered();
    void on_actionDelete_Frame_triggered();
    void on_actionColor_triggered();
    void on_actionClose_triggered();
    void on_actionNew_triggered();
//    void on_actionExport_triggered();

private slots:
    void previewAnimationTimerFinished();
    void on_colorPalletToolButton_pressed();
    void on_currentColorButton_clicked();
    void on_previousColor1Button_pressed();
    void on_previousColor2Button_pressed();
    void on_previousColor3Button_pressed();
    void on_previousColor4Button_pressed();
    void on_previousColor5Button_pressed();
    void on_previousColor6Button_pressed();
    void on_deleteFrameButton_clicked();
    void on_framesListWidget_itemPressed(QListWidgetItem *item);
    void on_largePixelToolButton_clicked();
    void on_mediumPixelToolButton_clicked();
    void on_smallPixelToolButton_clicked();
    void on_paintbrushToolButton_clicked();
    void on_eraseToolButton_clicked();
    void on_paintbucketToolButton_clicked();
    void on_mirrorToolButton_clicked();
    void on_flipToolButton_clicked();
    void on_darkenToolButton_clicked();
    void on_lightenToolButton_clicked();
    void on_colorDropperButton_clicked();
    void on_pencileToolButton_clicked();
    void on_clearButton_clicked();
    void on_undoButton_clicked();
    void on_redoButton_clicked();
    void on_duplicateFrameButton_pressed();
    void on_enlargeButton_clicked();
    void on_actualButton_clicked();

private:
    Ui::MainWindow *ui;
    Q_OBJECT
    int frameCount;
    int currentFrameNumber;
    int previewAnimationFrame;
    int previewSpeed;
    int frameRate;
    unsigned int currentFrameIndex;
    bool isEnlarged;
    bool projectSaved;
    QString filename;
    QTimer* previewAnimationTimer;
    QListWidgetItem* selectedItem;
    QPixmap *currentFrame;
    QColor *currentColor;
    QImage* frameImage;
    QColor color;
    bool adjustFPS();
    void importFramesList();
    void addEmptyFrameToFrameWindow();
    void removeNewFrameIconFromFrameWindow();
    void open();
    void save(bool);
    void updatePixelSizeSelectedButton(int);
    void updateToolSelectedButton(int);
    void sizeButtonUpdate(int);
    void closeEvent(QCloseEvent*);
    void restartNewProject();
};

#endif // MAINWINDOW_H
