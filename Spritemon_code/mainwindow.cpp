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
#include "ui_mainwindow.h"
#include "spritemon.h"
#include <QColor>
#include <QColorDialog>
#include <QPalette>
#include <QList>
#include <QListWidgetItem>
#include <QLayout>
#include <QPainter>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
//#include <Magick++.h>
//using namespace Magick;

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * The constructor for MainWindow. Sets all of the neccessary member variables to their
 * initial values.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize the first frame
    frameCount = 0;
    addEmptyFrameToFrameWindow();
    frameRate = 12;
    projectSaved = true;
    filename = "";
    isEnlarged = true;

    //timer for button highlight
    previewAnimationFrame = 0;
    adjustFPS();
    previewAnimationTimer = new QTimer(this);
    previewAnimationTimer->setSingleShot(true);
    QObject::connect(previewAnimationTimer, SIGNAL(timeout()), this, SLOT(previewAnimationTimerFinished()));

    updateToolSelectedButton(2);
    previewAnimationTimerFinished();
}

/**
 * @brief MainWindow::~MainWindow
 * The destructor for MainWindow. Deletes all elements of the ui by deleting ui itself.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * This method is called when the color pallet button has been pressed.
 * Opens the QColorDialog and allows the user to select a new color.
 * Once the user submits their coice, this method emits a signal to the model.
 * @brief MainWindow::on_colorPalletToolButton_pressed
 */
void MainWindow::on_colorPalletToolButton_pressed()
{
    color = QColorDialog::getColor();
    emit colorSelected(color);
    ui->colorPalletToolButton->setChecked(false);
    ui->statusLabel->setText("Color Palette: Use to select color to draw with.");

}

/**
 * This method updates the current and recent color buttons on the GUI
 * Slot that gets emit by the spritemon model whenever the colors need to be updated.
 * @brief MainWindow::updateRecentColors
 * @param list
 */
void MainWindow::updateRecentColors(QList<QColor> list)
{
    const QString colorStyle("QPushButton { background-color : %1; }");
    ui -> currentColorButton -> setStyleSheet(colorStyle.arg(list.first().name()));
    ui -> previousColor1Button -> setStyleSheet(colorStyle.arg(list.at(1).name()));
    ui -> previousColor2Button -> setStyleSheet(colorStyle.arg(list.at(2).name()));
    ui -> previousColor3Button -> setStyleSheet(colorStyle.arg(list.at(3).name()));
    ui -> previousColor4Button -> setStyleSheet(colorStyle.arg(list.at(4).name()));
    ui -> previousColor5Button -> setStyleSheet(colorStyle.arg(list.at(5).name()));
    ui -> previousColor6Button -> setStyleSheet(colorStyle.arg(list.at(6).name()));
}

/**
 * @brief MainWindow::on_currentColorButton_clicked
 * Called when the current color is clicked. Emits a signal to update the model.
 */
void MainWindow::on_currentColorButton_clicked()
{
    emit colorSelected(color);

    if(ui->eraseToolButton->isChecked() || ui->colorDropperButton->isChecked())
    {
        updateToolSelectedButton(2);
    }
    ui->statusLabel->setText("Current Color Selected.");

}

/**
 * Method for when recent button has been pressed.
 * emits a signal to update the model
 * @brief MainWindow::on_previousColor1Button_pressed
 */
void MainWindow::on_previousColor1Button_pressed()
{
    color = QColor(ui -> previousColor1Button->palette().background().color());
    emit colorSelected(color);
    if(ui->eraseToolButton->isChecked() || ui->colorDropperButton->isChecked())
    {
        updateToolSelectedButton(2);
    }
}

/**
 * Method for when recent button has been pressed.
 * emits a signal to update the model
 * @brief MainWindow::on_previousColor1Button_pressed
 */
void MainWindow::on_previousColor2Button_pressed()
{
    color = QColor(ui -> previousColor2Button->palette().background().color());
    emit colorSelected(color);
    if(ui->eraseToolButton->isChecked() || ui->colorDropperButton->isChecked())
    {
        updateToolSelectedButton(2);
    }
}

/**
 * Method for when recent button has been pressed.
 * emits a signal to update the model
 * @brief MainWindow::on_previousColor1Button_pressed
 */
void MainWindow::on_previousColor3Button_pressed()
{
    color = QColor(ui -> previousColor3Button->palette().background().color());
    emit colorSelected(color);
    if(ui->eraseToolButton->isChecked() || ui->colorDropperButton->isChecked())
    {
        updateToolSelectedButton(2);
    }
}

/**
 * Method for when recent button has been pressed.
 * emits a signal to update the model
 * @brief MainWindow::on_previousColor1Button_pressed
 */
void MainWindow::on_previousColor4Button_pressed()
{
    color = QColor(ui -> previousColor4Button->palette().background().color());
    emit colorSelected(color);
    if(ui->eraseToolButton->isChecked() || ui->colorDropperButton->isChecked())
    {
        updateToolSelectedButton(2);
    }
}

/**
 * Method for when recent button has been pressed.
 * emits a signal to update the model
 * @brief MainWindow::on_previousColor1Button_pressed
 */
void MainWindow::on_previousColor5Button_pressed()
{
    color = QColor(ui -> previousColor5Button->palette().background().color());
    emit colorSelected(color);
    if(ui->eraseToolButton->isChecked() || ui->colorDropperButton->isChecked())
    {
        updateToolSelectedButton(2);
    }
}

/**
 * Method for when recent button has been pressed.
 * emits a signal to update the model
 * @brief MainWindow::on_previousColor1Button_pressed
 */
void MainWindow::on_previousColor6Button_pressed()
{
    color = QColor(ui -> previousColor6Button->palette().background().color() );
    emit colorSelected(color);
    if(ui->eraseToolButton->isChecked() || ui->colorDropperButton->isChecked())
    {
        updateToolSelectedButton(2);
    }
}

/**
 * This method allows users to select and Item from the Frames Subview.
 * If the item is a valid frame, it will update current frame.
 * If the item is the addNewFrame button, then a new frame will be added.
 * @brief MainWindow::on_framesListWidget_itemPressed
 * @param item
 */
void MainWindow::on_framesListWidget_itemPressed(QListWidgetItem *item)
{
    if(item->text()  != "addFrame")
    {
        //save current frame Icon to Frames View
        updateSelectedFrameDisplay();

        //get new Index
        int index = item->text().toInt() - 1;
        sprite.currentFrame = index;

        //load new frame Icon to Frames view & set new selected
        QPixmap pxmap;
        pxmap.convertFromImage(*sprite.frames.at(sprite.currentFrame));
        QIcon newIcon(pxmap.copy(0,0,448,448));
        selectedItem = item;
        selectedItem->setIcon(newIcon);

        //currentFrame = frames[sprite.currentFrame];
    }
    else
    {
        //remove the addNewFrame button
        removeNewFrameIconFromFrameWindow();
        //add empty frame and addNewFrame buttons.
        addEmptyFrameToFrameWindow();
        projectSaved = false;
    }

    emit newFrameSelected(sprite.frames.at(sprite.currentFrame));
}

/**
 * Method used to save current Image to Frames Window
 * @brief MainWindow::updateSelectedFrameDisplay
 */
void MainWindow::updateSelectedFrameDisplay()
{
    QPixmap pxmap;
    pxmap.convertFromImage(*sprite.frames.at(sprite.currentFrame));
    QIcon currentIcon(pxmap.copy(0,0,448,448));
    selectedItem->setIcon(currentIcon);
    projectSaved = false;

}

/**
 * @brief MainWindow::updateSelectedFrameWithNewImage
 * @param img
 * Updates the selected frame by setting its image property
 * equal to the image parameter
 */
void MainWindow::updateSelectedFrameWithNewImage(QImage* img)
{
    sprite.frames.replace(sprite.currentFrame, img);
    updateSelectedFrameDisplay();
    projectSaved = false;
}

/**
 * Helper Method to add a frame to the Frames view.
 * @brief MainWindow::addEmptyFrameToFrameWindow
 */
void MainWindow::addEmptyFrameToFrameWindow()
{
      frameCount++;
      currentFrame = new QPixmap(450, 450);

      sprite.addFrame();
      QListWidgetItem* item = new QListWidgetItem(QString::number(frameCount), 0);
      item->setText(QString::number(frameCount));
      ui->framesListWidget->addItem(item);
      ui->framesListWidget->item(frameCount-1)->setSelected(true);
      selectedItem = item;
      currentFrame->convertFromImage(*sprite.frames.at(frameCount-1));
      QIcon currentIcon(currentFrame->copy(0, 0, 448, 448));
      item->setIcon(currentIcon);
      sprite.currentFrame = frameCount - 1;

      //Add the addNewFrame icod to the end of the list.
      QListWidgetItem *newItem = new QListWidgetItem("addFrame", 0);
      newItem->setText("addFrame");
      newItem->setIcon(QIcon(":/toolbar/icons/newImage.png"));
      ui->framesListWidget->addItem(newItem);
      ui->framesListWidget->scrollToItem(newItem);
      ui->framesListWidget->update();
      ui->statusLabel->setText("New Frame Added.");

}

/**
 * Helper method to remove the addNewButton Item so it can be re-added
 * after a new button has been added.
 * @brief MainWindow::removeNewFrameIconFromFrameWindow
 */
void MainWindow::removeNewFrameIconFromFrameWindow()
{
    ui->framesListWidget->takeItem(frameCount);
}

/**
 * When the trash button has been pressed, the selected item will be deleted.
 * Unless the item was the addNewFrame button.
 * @brief MainWindow::on_deleteFrameButton_clicked
 */
void MainWindow::on_deleteFrameButton_clicked()
{
    if(sprite.frames.count() > 1)
    {
         if (ui->framesListWidget->item(sprite.currentFrame)->text()  != "addFrame")
         {
            projectSaved = false;
            sprite.frames.removeAt(sprite.currentFrame);
            for(int i = 0; i < frameCount-1; i++)
            {
                selectedItem = ui->framesListWidget->item(i);
                QPixmap pxmap;
                pxmap.convertFromImage(*sprite.frames.at(i));
                QIcon newIcon(pxmap.copy(0,0,448,448));
                selectedItem->setIcon(newIcon);
            }

            QListWidgetItem *item = ui->framesListWidget->item(sprite.frames.length());
            delete item;
            if(sprite.currentFrame >= sprite.frames.count()){
                sprite.currentFrame--;
            }
            selectedItem =  ui->framesListWidget->item(sprite.currentFrame);
            selectedItem->setSelected(true);
            emit newFrameSelected(sprite.frames.at(sprite.currentFrame));

            frameCount--;

            repaint();
            ui->statusLabel->setText("Frame deleted.");
        }
    }
}

/**
 * @brief MainWindow::on_duplicateFrameButton_pressed
 * Copies the selected frame and appends it as a new frame at the end
 * of the frame list
 */
void MainWindow::on_duplicateFrameButton_pressed()
{

    if (ui->framesListWidget->item(sprite.currentFrame)->text() != "addFrame")
    {
        projectSaved = false;
        QImage* image = new QImage(sprite.frames.at(sprite.currentFrame)->copy(0,0,448,448));

        sprite.frames.append(image);

        removeNewFrameIconFromFrameWindow();
        //add empty frame and addNewFrame buttons.
        frameCount++;
        currentFrame = new QPixmap(450, 450);

        QListWidgetItem* item = new QListWidgetItem(QString::number(frameCount), 0);
        item->setText(QString::number(frameCount));
        ui->framesListWidget->addItem(item);
        currentFrame->convertFromImage(*sprite.frames.at(sprite.currentFrame));
        QIcon currentIcon(currentFrame->copy(0, 0, 448, 448));
        item->setIcon(currentIcon);

        //Add the addNewFrame icod to the end of the list.
        QListWidgetItem *newItem = new QListWidgetItem("", 0);
        newItem->setText("addFrame");
        newItem->setIcon(QIcon(":/toolbar/icons/newImage.png"));
        ui->framesListWidget->addItem(newItem);
        ui->framesListWidget->update();

        for(int i = 0; i < frameCount; i++)
        {
            selectedItem = ui->framesListWidget->item(i);
            QPixmap pxmap;
            pxmap.convertFromImage(*sprite.frames.at(i));
            QIcon newIcon(pxmap.copy(0,0,448,448));
            selectedItem->setIcon(newIcon);
        }
        if(sprite.currentFrame >= sprite.frames.count())
        {
            sprite.currentFrame--;
        }
        selectedItem =  ui->framesListWidget->item(sprite.currentFrame);
        selectedItem->setSelected(true);
        emit newFrameSelected(sprite.frames.at(sprite.currentFrame));

        repaint();
        ui->statusLabel->setText("Frame duplicated.");
    }
}

/**
 * @brief MainWindow::on_smallPixelToolButton_clicked
 * Sets the brush size to 1 pixel
 */
void MainWindow::on_smallPixelToolButton_clicked()
{
    emit pixelNumberSelected(1);
    updatePixelSizeSelectedButton(1);
}

/**
 * @brief MainWindow::on_mediumPixelToolButton_clicked
 * Sets the brush size to 2x2 pixels
 */
void MainWindow::on_mediumPixelToolButton_clicked()
{
    emit pixelNumberSelected(2);
    updatePixelSizeSelectedButton(2);
}

/**
 * @brief MainWindow::on_largePixelToolButton_clicked
 * Sets the brush size to 3x3 pixels
 */
void MainWindow::on_largePixelToolButton_clicked()
{
    emit pixelNumberSelected(3);
    updatePixelSizeSelectedButton(3);
}

/**
 * @brief MainWindow::updatePixelSizeSelectedButton
 * @param buttonNumber
 * Makes sure that only one pixel size button can be selected at a time
 */
void MainWindow::updatePixelSizeSelectedButton(int buttonNumber)
{
    if(buttonNumber == 1)
    {
        ui->largePixelToolButton->setChecked(false);
        ui->mediumPixelToolButton->setChecked(false);
        ui->smallPixelToolButton->setChecked(true);
    }
    else if (buttonNumber == 2)
    {
        ui->largePixelToolButton->setChecked(false);
        ui->mediumPixelToolButton->setChecked(true);
        ui->smallPixelToolButton->setChecked(false);
    }
    else
    {
        ui->largePixelToolButton->setChecked(true);
        ui->mediumPixelToolButton->setChecked(false);
        ui->smallPixelToolButton->setChecked(false);
    }

    ui->largePixelToolButton->update();
    ui->mediumPixelToolButton->update();
    ui->smallPixelToolButton->update();
}

/**
 * @brief MainWindow::previewAnimationTimerFinished
 * The method that is called when the fps timer is finished
 * to update the preview label
 */
void MainWindow::previewAnimationTimerFinished(){
    if(adjustFPS()){
        if(previewAnimationFrame < sprite.frames.size() - 1){
            previewAnimationFrame++;
        } else {
            previewAnimationFrame = 0;
        }
        QImage* currentImage = sprite.frames[previewAnimationFrame];
        QImage scaledImage;
        if(isEnlarged){
            scaledImage = currentImage->scaled(128, 128);
            ui->previewLabel->setAlignment(Qt::AlignCenter);
        } else {
            scaledImage = currentImage->scaled(sprite.spriteWidth, sprite.spriteWidth);
            ui->previewLabel->setAlignment(Qt::AlignCenter);
        }

        ui->previewLabel->setPixmap(QPixmap::fromImage(scaledImage));
    }
    previewAnimationTimer->start(previewSpeed);
}

/**
 * @brief MainWindow::adjustFPS
 * @return
 * Adjusts the fps based on the fps slider's position
 */
bool MainWindow::adjustFPS(){
    if (ui->fpsSlider->value() == 0){
        return false;
    } else {
        previewSpeed = 1000 / ui->fpsSlider->value();
        return true;
    }
}

/**
 * @brief MainWindow::updateToolSelectedButton
 * @param buttonNumber
 * Makes sure that only one tool button is selected at a time
 */
void MainWindow::updateToolSelectedButton(int buttonNumber)
{
    if (buttonNumber == 2)
    {
        ui->paintbrushToolButton->setChecked(true);
        ui->pencileToolButton->setChecked(false);
        ui->eraseToolButton->setChecked(false);
        ui->paintbucketToolButton->setChecked(false);
        ui->mirrorToolButton->setChecked(false);
        ui->flipToolButton->setChecked(false);
        ui->darkenToolButton->setChecked(false);
        ui->lightenToolButton->setChecked(false);
        ui->colorDropperButton->setChecked(false);
        ui->statusLabel->setText("Paint Brush: Draw on the main frame by clicking and dragging. Color can be selected from the color palette, size can be selected from pixel size options.");

    }
    else if (buttonNumber == 3)
    {
        ui->paintbrushToolButton->setChecked(false);
        ui->pencileToolButton->setChecked(true);
        ui->eraseToolButton->setChecked(false);
        ui->paintbucketToolButton->setChecked(false);
        ui->mirrorToolButton->setChecked(false);
        ui->flipToolButton->setChecked(false);
        ui->darkenToolButton->setChecked(false);
        ui->lightenToolButton->setChecked(false);
        ui->colorDropperButton->setChecked(false);
        ui->statusLabel->setText("Fill All Color Tool: Changes all of the identical colored pixels to the current selected color.");

    }
    else if (buttonNumber == 5)
    {
        ui->paintbrushToolButton->setChecked(false);
        ui->pencileToolButton->setChecked(false);
        ui->eraseToolButton->setChecked(true);
        ui->paintbucketToolButton->setChecked(false);
        ui->mirrorToolButton->setChecked(false);
        ui->flipToolButton->setChecked(false);
        ui->darkenToolButton->setChecked(false);
        ui->lightenToolButton->setChecked(false);
        ui->colorDropperButton->setChecked(false);
        ui->statusLabel->setText("Eraser: Erases any pixels that are clicked and dragged over. Size is adjustable with pixel size selector.");
    }
    else if (buttonNumber == 6)
    {
        ui->paintbrushToolButton->setChecked(false);
        ui->pencileToolButton->setChecked(false);
        ui->eraseToolButton->setChecked(false);
        ui->paintbucketToolButton->setChecked(true);
        ui->mirrorToolButton->setChecked(false);
        ui->flipToolButton->setChecked(false);
        ui->darkenToolButton->setChecked(false);
        ui->lightenToolButton->setChecked(false);
        ui->colorDropperButton->setChecked(false);
        ui->statusLabel->setText("Fill Group Tool: When clicked on a pixel, changes all identical pixels that are attached to each other to current color selected.");

    }
    else if (buttonNumber == 7)
    {
        ui->paintbrushToolButton->setChecked(false);
        ui->pencileToolButton->setChecked(false);
        ui->eraseToolButton->setChecked(false);
        ui->paintbucketToolButton->setChecked(false);
        ui->mirrorToolButton->setChecked(true);
        ui->flipToolButton->setChecked(false);
        ui->darkenToolButton->setChecked(false);
        ui->lightenToolButton->setChecked(false);
        ui->colorDropperButton->setChecked(false);
        ui->statusLabel->setText("Mirror Tool: Draws a mirrored image on both left and right side of the canvas. Use for symmetry.");

    }
    else if(buttonNumber == 8)
    {
        ui->paintbrushToolButton->setChecked(false);
        ui->pencileToolButton->setChecked(false);
        ui->eraseToolButton->setChecked(false);
        ui->paintbucketToolButton->setChecked(false);
        ui->mirrorToolButton->setChecked(false);
        ui->flipToolButton->setChecked(true);
        ui->darkenToolButton->setChecked(false);
        ui->lightenToolButton->setChecked(false);
        ui->colorDropperButton->setChecked(false);
        ui->statusLabel->setText("Flip Image Tool: Click this tool and then click on the canvas to flip the left and right sides of the image.");

    }
    else if (buttonNumber == 9)
    {
        ui->paintbrushToolButton->setChecked(false);
        ui->pencileToolButton->setChecked(false);
        ui->eraseToolButton->setChecked(false);
        ui->paintbucketToolButton->setChecked(false);
        ui->mirrorToolButton->setChecked(false);
        ui->flipToolButton->setChecked(false);
        ui->darkenToolButton->setChecked(true);
        ui->lightenToolButton->setChecked(false);
        ui->colorDropperButton->setChecked(false);
        ui->statusLabel->setText("Darken Tool. Darkens area by clicking and dragging on frame. Size is adjustable with pixel size selector.");

    }
    else if(buttonNumber == 10)
    {
        ui->paintbrushToolButton->setChecked(false);
        ui->pencileToolButton->setChecked(false);
        ui->eraseToolButton->setChecked(false);
        ui->paintbucketToolButton->setChecked(false);
        ui->mirrorToolButton->setChecked(false);
        ui->flipToolButton->setChecked(false);
        ui->darkenToolButton->setChecked(false);
        ui->lightenToolButton->setChecked(true);
        ui->colorDropperButton->setChecked(false);
        ui->statusLabel->setText("Lighten Tool. Lightens area by clicking and dragging on frame. Size is adjustable with pixel size selector.");

    }
    else if(buttonNumber == 11)
    {
        ui->paintbrushToolButton->setChecked(false);
        ui->pencileToolButton->setChecked(false);
        ui->eraseToolButton->setChecked(false);
        ui->paintbucketToolButton->setChecked(false);
        ui->mirrorToolButton->setChecked(false);
        ui->flipToolButton->setChecked(false);
        ui->darkenToolButton->setChecked(false);
        ui->lightenToolButton->setChecked(false);
        ui->colorDropperButton->setChecked(true);
        ui->statusLabel->setText("Color Grabber Tool. Select any pixel on the frame to use as your current color");
    }

    ui->paintbrushToolButton->update();
    ui->pencileToolButton->update();
    ui->eraseToolButton->update();
    ui->paintbucketToolButton->update();
    ui->mirrorToolButton->update();
    ui->flipToolButton->update();
    ui->darkenToolButton->update();
    ui->lightenToolButton->update();
    ui->colorDropperButton->update();

    emit toolSelected(buttonNumber);
}

/**
 * @brief MainWindow::on_paintbrushToolButton_clicked
 * Selects the paint brush when clicked
 */
void MainWindow::on_paintbrushToolButton_clicked()
{
    updateToolSelectedButton(2);
}

/**
 * @brief MainWindow::on_pencileToolButton_clicked
 * Selects the pencil tool when clicked
 */
void MainWindow::on_pencileToolButton_clicked()
{
    updateToolSelectedButton(3);
}

/**
 * @brief MainWindow::on_eraseToolButton_clicked
 * Selects the erase tool when clicked
 */
void MainWindow::on_eraseToolButton_clicked()
{
    updateToolSelectedButton(5);
}

/**
 * @brief MainWindow::on_paintbucketToolButton_clicked
 * Selects the paint bucket tool when clicked
 */
void MainWindow::on_paintbucketToolButton_clicked()
{
    updateToolSelectedButton(6);
}

/**
 * @brief MainWindow::on_mirrorToolButton_clicked
 * Selects the mirror tool when clicked
 */
void MainWindow::on_mirrorToolButton_clicked()
{
    updateToolSelectedButton(7);
}

/**
 * @brief MainWindow::on_flipToolButton_clicked
 * Selects the flip tool when clicked
 */
void MainWindow::on_flipToolButton_clicked()
{
    updateToolSelectedButton(8);
}

/**
 * @brief MainWindow::on_darkenToolButton_clicked
 * Selects the darken tool when clicked
 */
void MainWindow::on_darkenToolButton_clicked()
{
    updateToolSelectedButton(9);
}

/**
 * @brief MainWindow::on_lightenToolButton_clicked
 * Selects the lighten tool when clicked
 */
void MainWindow::on_lightenToolButton_clicked()
{
    updateToolSelectedButton(10);
}

/**
 * @brief MainWindow::on_colorDropperButton_clicked
 * Selects the color dropper tool when clicked
 */
void MainWindow::on_colorDropperButton_clicked()
{
    updateToolSelectedButton(11);
}

/**
 * @brief MainWindow::on_clearButton_clicked
 * Selects the clear tool when clicked
 */
void MainWindow::on_clearButton_clicked()
{
    emit canvasButtonClicked("clear");
    ui->statusLabel->setText("Current frame cleared.");
    projectSaved = false;

}

/**
 * @brief MainWindow::on_undoButton_clicked
 * Undoes the last action
 */
void MainWindow::on_undoButton_clicked()
{
    emit canvasButtonClicked("undo");
    ui->statusLabel->setText("Undo last action.");
    projectSaved = false;

}

/**
 * @brief MainWindow::on_redoButton_clicked
 * Redoes the last undone action
 */
void MainWindow::on_redoButton_clicked()
{
    emit canvasButtonClicked("redo");
    ui->statusLabel->setText("Redo last action.");
    projectSaved = false;

}

/**
 * @brief MainWindow::on_actionSave_triggered
 * Saves the project
 */
void MainWindow::on_actionSave_triggered()
{
    if(!projectSaved)
    {
       save(false);
    }
}

/**
 * @brief MainWindow::on_actionSave_As_triggered
 * Saves the project as
 */
void MainWindow::on_actionSave_As_triggered()
{
       save(true);
}

/**
 * @brief MainWindow::save
 * @param saveAs
 * Saves the file to a .ssp file
 */
void MainWindow::save(bool saveAs)
{
    QString output = sprite.getOutputStream();
    QFileDialog *fileDialog = new QFileDialog;
    fileDialog->setDefaultSuffix("ssp");
    if(filename == "" || saveAs)
    {
        filename = fileDialog->getSaveFileName(this, tr("Save File"), "", "Text files (*.ssp)");
    }
    QFile f(filename);
    if(f.open(QIODevice::WriteOnly))
    {
        QTextStream stream( &f );
        stream << sprite.spriteWidth << " " << sprite.spriteWidth << endl;
        stream << sprite.frames.size() << endl;
        stream << output << endl;
        f.close();
        projectSaved = true;
        ui->statusLabel->setText("Project Saved.");
    }
}

/**
 * @brief MainWindow::on_actionOpen_triggered
 * Called when the open button is clicked
 */
void MainWindow::on_actionOpen_triggered()
{
    open();
}

/**
 * @brief MainWindow::open
 * Opens a .ssp file and converts it into the frames that comprise a project
 */
void MainWindow::open()
{
    filename = QFileDialog::getOpenFileName(this, "Select a file to open", QDir::homePath(), tr("Text files (*.ssp)"));
    QFile f(filename);
    if (f.open(QIODevice::ReadOnly))
    {

       sprite.frames.clear();

       QTextStream in(&f);
       int numberOfFrames = 0;
       int count = 0;
       while (!in.atEnd() && count < 2)
       {
          QString line = in.readLine();
          if(count == 0)
          {
              sprite.spriteWidth = line.split(" ")[0].toInt();
              emit setFrameSizeTo(sprite.spriteWidth);
          }
          else if (count == 1)
          {
              numberOfFrames = line.toInt();
          }
          count++;
       }
       QImage scaledImage;
       for (int frame = 0; frame < numberOfFrames; frame++)
       {
           QImage *img = new QImage(448, 448, QImage::Format_ARGB32);
           for (int row = 0; row < sprite.spriteWidth; row++){
               QString line = in.readLine();
               for (int column = 0; column < sprite.spriteWidth; column++)
               {
                   QColor color;
                   int red;
                   int green;
                   int blue;
                   int alpha;
                   for (int l = 0; l < 4; l++) {
                       switch(l) {
                       case 0:
                           red = line.split(" ")[column * 4].toInt();
                           break;
                       case 1:
                           green = line.split(" ")[column * 4 + 1].toInt();
                           break;
                       case 2:
                           blue = line.split(" ")[column * 4 + 2].toInt();
                           break;
                       case 3:
                           alpha = line.split(" ")[column * 4 + 3].toInt();
                           break;
                       }
                   }
                   color = QColor(red, green, blue, alpha);
                   int pixelWidth = 448 / sprite.spriteWidth;
                   int startingXPixel = pixelWidth*column; //the leftmost pixel in the column
                   int endingXPixel = startingXPixel + pixelWidth; //the rightmost pixel in the column
                   int startingYPixel = pixelWidth*row; //the top pixel in the row
                   int endingYPixel = startingYPixel + pixelWidth; //the bottom pixel in the row

                   for(int x = startingXPixel; x < endingXPixel; x++)
                   {
                       for(int y = startingYPixel; y < endingYPixel; y++)
                       {
                           img->setPixel(x,y,color.rgba());
                       }
                   }
               }
           }
           sprite.frames.append(img);
       }
       importFramesList();
       projectSaved = true;
       ui->statusLabel->setText("Project Imported");
    }
}

/**
 * @brief MainWindow::importFramesList
 * Gets the frames from the newly added file and adds them to
 * the frame section of the gui
 */
void MainWindow::importFramesList()
{
    updateToolSelectedButton(2);
    while(ui->framesListWidget->count() > 0)
    {
        QListWidgetItem* x = ui->framesListWidget->takeItem(0);
        delete x;
    }
    frameCount = 0;

    for(int i = 0; i < sprite.frames.length() ; i++)
    {
        //add empty frame and addNewFrame buttons.
        frameCount++;
        currentFrame = new QPixmap(448, 448);

        QListWidgetItem* item = new QListWidgetItem(QString::number(i+1), 0);
        item->setText(QString::number(i+1));
        ui->framesListWidget->addItem(item);
        currentFrame->convertFromImage(*sprite.frames.at(i));
        QIcon currentIcon(currentFrame->copy(0, 0, 448, 448));
        item->setIcon(currentIcon);
        repaint();
    }

    for(int i = 0; i < frameCount; i++)
    {
        selectedItem = ui->framesListWidget->item(i);
        QPixmap pxmap;
        pxmap.convertFromImage(*sprite.frames.at(i));
        QIcon newIcon(pxmap.copy(0,0,448,448));
        selectedItem->setIcon(newIcon);
    }

    selectedItem =  ui->framesListWidget->item(0);
    selectedItem->setSelected(true);
    emit newFrameSelected(sprite.frames.at(0));

    //Add the addNewFrame icod to the end of the list.
    QListWidgetItem *newItem = new QListWidgetItem("", 0);
    newItem->setText("addFrame");
    newItem->setIcon(QIcon(":/toolbar/icons/newImage.png"));
    ui->framesListWidget->addItem(newItem);
    ui->framesListWidget->update();
}

/**
 * @brief MainWindow::on_enlargeButton_clicked
 * Called when the enlarge button is clicked to set the preview
 * to the larger format
 */
void MainWindow::on_enlargeButton_clicked()
{
    sizeButtonUpdate(1);
    isEnlarged = true;
    ui->statusLabel->setText("Preview changed to enlarged pixel view");
}

/**
 * @brief MainWindow::on_actualButton_clicked
 * Called when the actual size button is clicked to set the preview
 * to the actual size of the sprite
 */
void MainWindow::on_actualButton_clicked()
{
    sizeButtonUpdate(2);
    isEnlarged = false;
    ui->statusLabel->setText("Preview changed to actual pixel size");
}

/**
 * @brief MainWindow::sizeButtonUpdate
 * @param number
 * Ensures that only one size button can be selected at once
 */
void MainWindow::sizeButtonUpdate(int number)
{
    if(number == 1)
    {
        ui->enlargeButton->setChecked(true);
        ui->actualButton->setChecked(false);
    }
    else if (number == 2)
    {
        ui->enlargeButton->setChecked(false);
        ui->actualButton->setChecked(true);
    }
}

/**
 * @brief MainWindow::on_actionUndo_triggered
 * Called when the undo button is clicked
 */
void MainWindow::on_actionUndo_triggered()
{
    on_undoButton_clicked();

}

/**
 * @brief MainWindow::on_actionRedo_triggered
 * Called when the redo button is clicked
 */
void MainWindow::on_actionRedo_triggered()
{
    on_redoButton_clicked();

}

/**
 * @brief MainWindow::on_actionClear_Frame_triggered
 * Called when the x button in the canvas is clicked
 */
void MainWindow::on_actionClear_Frame_triggered()
{
    on_clearButton_clicked();
}

/**
 * @brief MainWindow::on_actionNew_Frame_triggered
 * Called when the new frame button is clicked
 */
void MainWindow::on_actionNew_Frame_triggered()
{
    //remove the addNewFrame button
    removeNewFrameIconFromFrameWindow();
    //add empty frame and addNewFrame buttons.
    addEmptyFrameToFrameWindow();
    projectSaved = false;

}

/**
 * @brief MainWindow::on_actionDuplicate_Frame_triggered
 * Called when the duplicate frame button is clicked
 */
void MainWindow::on_actionDuplicate_Frame_triggered()
{
    on_duplicateFrameButton_pressed();
}

/**
 * @brief MainWindow::on_actionDelete_Frame_triggered
 * Called when the delete button is clicked
 */
void MainWindow::on_actionDelete_Frame_triggered()
{
    on_deleteFrameButton_clicked();
}

/**
 * @brief MainWindow::on_actionColor_triggered
 * Called when the color pallet is clicked
 */
void MainWindow::on_actionColor_triggered()
{
    on_colorPalletToolButton_pressed();
}

/**
 * @brief MainWindow::on_actionClose_triggered
 * Called when the window is closed
 */
void MainWindow::on_actionClose_triggered()
{
    if(!projectSaved)
    {
        QMessageBox prompt;
        prompt.setText(trUtf8("Unsaved Changes Exist"));
        prompt.setInformativeText("Would you like to save before closing Spritemon?");
        QAbstractButton *yes = prompt.addButton(trUtf8("Save"), QMessageBox::YesRole);
        QAbstractButton *ignore = prompt.addButton(trUtf8("Ignore"), QMessageBox::NoRole);
        QAbstractButton *cancel = prompt.addButton(trUtf8("Cancel"), QMessageBox::ResetRole);
        prompt.setIcon(QMessageBox::Warning);
        prompt.exec();

        if (prompt.clickedButton() == yes)
        {
            save(false);
            if(projectSaved)
            {
                QApplication::quit();
            }
        }
        else if (prompt.clickedButton() == ignore)
        {
            QApplication::quit();
        }
    }
    else {
        QApplication::quit();
    }
}

/**
 * @brief MainWindow::closeEvent
 * @param event
 * Closes the window and ensures everything is saved
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!projectSaved)
    {

        QMessageBox prompt;
        prompt.setText(trUtf8("Unsaved Changes Exist"));
        prompt.setInformativeText("Would you like to save before closing Spritemon?");
        QAbstractButton *yes = prompt.addButton(trUtf8("Save"), QMessageBox::YesRole);
        QAbstractButton *ignore = prompt.addButton(trUtf8("Ignore"), QMessageBox::NoRole);
        QAbstractButton *cancel = prompt.addButton(trUtf8("Cancel"), QMessageBox::ResetRole);
        prompt.setIcon(QMessageBox::Warning);
        prompt.exec();

        if (prompt.clickedButton() == yes)
        {
            save(false);
            if(projectSaved)
            {
                QApplication::quit();
            }
        }
        else if (prompt.clickedButton() == cancel)
        {
            event->ignore();
        }
        else
        {
            event->accept();
        }
    }
    else
    {
        event->accept();
    }
}

/**
 * @brief MainWindow::on_actionNew_triggered
 * Called when the new button is clicked
 */
void MainWindow::on_actionNew_triggered()
{
    if(!projectSaved)
    {
        QMessageBox prompt;
        prompt.setText(trUtf8("Unsaved Changes Exist"));
        prompt.setInformativeText("Would you like to save before starting a new project?");
        QAbstractButton *yes = prompt.addButton(trUtf8("Save"), QMessageBox::YesRole);
        QAbstractButton *no = prompt.addButton(trUtf8("Ignore"), QMessageBox::NoRole);
        QAbstractButton *cancel = prompt.addButton(trUtf8("Cancel"), QMessageBox::ResetRole);
        prompt.setIcon(QMessageBox::Warning);
        prompt.exec();

        if (prompt.clickedButton() == yes)
        {
            save(false);
            if(projectSaved)
            {
                restartNewProject();
            }
        }
        else if (prompt.clickedButton() == no)
        {
            restartNewProject();
        }
    }
    else {
        restartNewProject();
    }
}

/**
 * @brief MainWindow::restartNewProject
 * Called when the frame size is changed after a project has been started
 */
void MainWindow::restartNewProject()
{
    askForFrameWidth();

    // Initialize the first frame
    frameCount = 0;
    addEmptyFrameToFrameWindow();
    frameRate = 12;
    projectSaved = true;
    filename = "";

    //timer for button highlight
    previewAnimationFrame = 0;
    adjustFPS();
    previewAnimationTimer = new QTimer(this);
    previewAnimationTimer->setSingleShot(true);
    QObject::connect(previewAnimationTimer, SIGNAL(timeout()), this, SLOT(previewAnimationTimerFinished()));

    updateToolSelectedButton(2);
    previewAnimationTimerFinished();
    sprite.frames.clear();
    sprite.addFrame();
    sprite.currentFrame = 0;
    emit newFrameSelected(sprite.frames.at(sprite.currentFrame));

    importFramesList();
    projectSaved = true;
    ui->statusLabel->setText("New Project Created");
}

/**
 * @brief MainWindow::askForFrameWidth
 * The user is prompted for the desired frame width
 */
void MainWindow::askForFrameWidth()
{
    QMessageBox prompt;
    prompt.setText(trUtf8("New Project"));
    prompt.setInformativeText("Please select the desired pixel frame size");
    QAbstractButton *x64 = prompt.addButton(trUtf8("64 x 64"), QMessageBox::YesRole);
    QAbstractButton *x32 = prompt.addButton(trUtf8("32 x 32"), QMessageBox::NoRole);
    QAbstractButton *x16 = prompt.addButton(trUtf8("16 x 16"), QMessageBox::ResetRole);
    prompt.setIcon(QMessageBox::Question);
    prompt.exec();

    if (prompt.clickedButton() == x16)
    {
        emit setFrameSizeTo(16);
        sprite.spriteWidth = 16;
    }
    else if (prompt.clickedButton() == x32)
    {
        emit setFrameSizeTo(32);
        sprite.spriteWidth = 32;
    }
    else {
        emit setFrameSizeTo(64);
        sprite.spriteWidth = 64;
    }

}

//void MainWindow::on_actionExport_triggered()
//{
//    QLinkedList<Image> newFrames;
//    for(int i = 0; i < sprite.frames.size(); i++)
//    {
//        Magick::Image appended;
//        QImageWriter writer("../spritemonTest.tif");
//        appended.read("../spritemonTest.tif");
//        appended.animationDelay(previewSpeed);
//        newFrames.push_back(appended);
//    }
//    writeImages(newFrames.begin(), newFrames.end(), "../appended_images.gif");
//}


