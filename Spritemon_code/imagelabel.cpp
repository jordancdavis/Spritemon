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

#include "imagelabel.h"
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

//refer to http://stackoverflow.com/questions/28026939/drawing-using-qimage-qpixmap-and-qlabel

/**
 * A canvas for drawing pixels. Set the frame tool to chang the way you add pixels to the canvas
 * @brief ImageLabel::ImageLabel
 * @param parent
 * @param image
 * @param frameNumber
 */
ImageLabel::ImageLabel( QWidget* parent, QImage* image, int frameNumber)
    : QLabel(parent)
{
    sizeX=448;
    sizeY=448;
    numberOfPixels = 64; //the number of pixels per frame (width)
    pixelNumber = 2; //the width of the brush
    pixelWidth = sizeX/numberOfPixels;
    pxmap = NULL;
    frame = image;
    frameNum = frameNumber;
    img = new QImage(sizeX, sizeY, QImage::Format_ARGB32);
    color = QColor(0,0,0);
    toolNumber = 2;

    //initialize undo list
    QImage* emptyImage = new QImage(sizeX, sizeY, QImage::Format_ARGB32);
    undoList.append(emptyImage);

    updateCanvasToNewImage(frame);
}

/**
 * Destructor for ImageLabel
 * @brief ImageLabel::~ImageLabel
 */
ImageLabel::~ImageLabel()
{
    delete(pxmap);
    delete(img);
}

QImage *tempimg;
QPixmap *temppx;

/**
 * After each mouse click the Model and View will be notified to update contents.
 * @brief ImageLabel::mouseReleaseEvent
 * @param event
 */
void ImageLabel::mouseReleaseEvent(QMouseEvent *event)
{
    detectCanvasChange(*img);
}

/**
 * When a mouse is presses the canvas performs the specified toolNumber task
 * @brief ImageLabel::mousePressEvent
 * @param event
 */
void ImageLabel::mousePressEvent(QMouseEvent* event)
{
    if(toolNumber == 2 || toolNumber == 3 || toolNumber == 5 || toolNumber == 7 || toolNumber == 9 || toolNumber == 10 ) // Pencil Tool , Paint Brush Tool  DONE
    {
        //2 = brush     //3 = fillAllColor      //5 = erase         //7 = mirror    //9 = darken        //10 = lighten
        colorPixel(event);
    }
    else if (toolNumber == 6) //fill Tool
    {
        prepareForFill(event);
    }
    else if(toolNumber == 8) // flip Tool
    {
        QImage mirrored = img->mirrored(true, false);
        *img = mirrored;
        frame = this->img;
        this->pxmap = new QPixmap();
        pxmap->convertFromImage(*this->img);
        this->setPixmap(QPixmap::fromImage(*img));
        emit updateCurrentFrameDisplay();
    }
    else if(toolNumber == 11) // Color Picker DONE
    {
        getPixelColor(event);
    }
    else
    {
        return;
    }
}

/**
 * When the mouse is clicked and moved, the canvas updates with specified tool type
 * @brief ImageLabel::mouseMoveEvent
 * @param event
 */
void ImageLabel::mouseMoveEvent(QMouseEvent* event)
{
    if(toolNumber == 2 || toolNumber == 5 || toolNumber == 7 || toolNumber == 9 || toolNumber == 10) // PaintBrush Tool DONE
    {
        //2 = brush     //5 = erase         //7 = mirror        //9 = darken        //10 = lighten
        colorPixel(event);
    }
    else //Do nothing.
    {
        return;
    }
}

/**
 *  Method that paints a pixel on the pixmap
 * @brief ImageLabel::colorPixel
 * @param event
 */
void ImageLabel::colorPixel(QMouseEvent* event)
{
    int mousePositionX = event->pos().x();  //get mouse Xposition
    int mousePositionY = event->pos().y();  //get mouse Yposition
    int columnNumber = mousePositionX / pixelWidth; //determines the column
    int rowNumber = mousePositionY / pixelWidth; //determines the row
    int startingXPixel = pixelWidth*columnNumber; //the leftmost pixel in the column
    int endingXPixel = startingXPixel + (pixelNumber * pixelWidth); //the rightmost pixel in the column
    int startingYPixel = pixelWidth*rowNumber; //the top pixel in the row
    int endingYPixel = startingYPixel + (pixelNumber * pixelWidth); //the bottom pixel in the row

    if(toolNumber == 3)    //fill
    {
        QRgb pixColor = QRgb(img->pixel(mousePositionX, mousePositionY));
            if(pixColor != 0000) // this is the number for transparency
            {
                QColor fill = QColor(pixColor);
                fillColor(fill);
            }
    }
    else
    {
        int z = 0; //used for mirror image
        for(int x = startingXPixel; x < endingXPixel; x++)
        {
            for(int y = startingYPixel; y < endingYPixel; y++)
            {
                //prevents out of range error.
                if(y < 448 && x < 448 && y > 0 && x > 0)
                {
                    //decide pixel modify tool type
                    if(toolNumber == 2 || toolNumber == 4)  //draw
                    {
                        img->setPixel(x,y,color.rgba());
                    }
                    else if(toolNumber == 5)    //Erase Tool
                    {
                        img->setPixel(x,y,0000);
                    }
                    else if(toolNumber == 7) //Mirror Tool
                    {
                        img->setPixel(x,y,color.rgba());
                        int cnumb = 448 / pixelWidth; //determines the right most column
                        int mirrorX = (pixelWidth * cnumb) - x - 1 ; //mirror x location
                        img->setPixel(mirrorX,y,color.rgba());
                    }
                    else if(toolNumber == 9)    //Darken Tool
                    {
                        QRgb pixColor = QRgb(img->pixel(mousePositionX, mousePositionY));
                        if(pixColor != 0000) // this is the number for transparency
                        {
                            QColor dark = QColor(pixColor);
                            dark = dark.darker(101); //keep this at 101 (if < 100 makes lighter)
                            img->setPixel(x,y,dark.rgba());
                        }
                    }
                    else if(toolNumber == 10)   //Lighten Tool
                    {
                        QRgb pixColor = QRgb(img->pixel(mousePositionX, mousePositionY));
                        if(pixColor != 0000) // this is the number for transparency
                        {
                            QColor light = QColor(pixColor);
                            light = light.lighter(102); //keep this at 101 ( if < 100 makes darker)
                            img->setPixel(x,y,light.rgba());
                        }
                    }
                }
                z++; //used for mirror image.
            }
        }
    }

    frame = this->img;
    this->pxmap = new QPixmap();
    pxmap->convertFromImage(*this->img);
    this->setPixmap(QPixmap::fromImage(*img));
    emit updateCurrentFrameDisplay();
}

/**
 * Method used to get the color from a specified pixel
 * @brief ImageLabel::getPixelColor
 * @param event
 */
void ImageLabel::getPixelColor(QMouseEvent* event)
{
    int mousePositionX = event->pos().x();  //get mouse Xposition
    int mousePositionY = event->pos().y();  //get mouse Yposition

    QRgb pixColor = QRgb(img->pixel(mousePositionX, mousePositionY));
    if(pixColor == 0000 || pixColor  == color.rgba()) // this is the number for transparency
    {
        return;
    }
    //color = pixColor;
    emit dropperColor(pixColor);
}


/**
 * Loops through all pixels and compares them with the passed in color.
 * If they match, updates the pixel to the current color.
 * @brief ImageLabel::fillColor
 * @param modColor
 */
void ImageLabel::fillColor(QColor modColor)
{
    for(int x = 1 ; x <= 448-pixelWidth+1; x = x+pixelWidth)
    {
        for(int y = 1 ; y <= 448-pixelWidth+1; y = y+pixelWidth)
        {
            QRgb fill = QRgb(img->pixel(x, y));
            if(fill == modColor.rgba()) // this is the number for transparency
            {
                for(int left = x-1; left < x+pixelWidth-1; left++)
                {
                    for(int top = y-1; top < y+pixelWidth-1; top++)
                    {
                        img->setPixel(left,top,color.rgba());
                    }
                }
            }
        }
    }
}

/**
 *  Slot to receive and update the users new selected color
 * @brief ImageLabel::updateCurrentColor
 * @param _color
 */
void ImageLabel::updateCurrentColor(QColor _color)
{
    color = _color;
}

/**
 * Slot to receive and update the pixel number (brush size) for drawing
 * @brief ImageLabel::updatePixelNumber
 * @param number
 */
void ImageLabel::updatePixelNumber(int number)
{
    pixelNumber = number;
}

/**
 * Slot to receive and update the specified tool from the MainWindow.
 * @brief ImageLabel::updateToolNumber
 * @param number
 */
void ImageLabel::updateToolNumber(int number)
{
    toolNumber = number;
}

/**
 * Driver method for filling a group of colors that are all the same color and touching eachother
 * @brief ImageLabel::prepareForFill
 * @param event
 */
void ImageLabel::prepareForFill(QMouseEvent* event)
{
    int columnNumber = event->pos().x() / pixelWidth; //determines the column
    int rowNumber = event->pos().y() / pixelWidth; //determines the row
    int startingXPixel = pixelWidth*columnNumber; //the leftmost pixel in the column
    int startingYPixel = pixelWidth*rowNumber; //the top pixel in the row
    //colorPixel(event);
    QRgb pixColor = QRgb(img->pixel(event->pos().x(), event->pos().y()));
    if(pixColor != 0000) // this is the number for transparency
    {
        if(pixColor != color.rgba())
        {
            QColor fill = QColor(pixColor);
            QPoint p(startingXPixel+1, startingYPixel+1);
            fillAdjacentColor(p, fill);
        }
    }
    frame = this->img;
    this->pxmap = new QPixmap();
    pxmap->convertFromImage(*this->img);
    this->setPixmap(QPixmap::fromImage(*img));
    emit updateCurrentFrameDisplay();
}

/**
 * helper method to fill a color used for the group fill tool
 * @brief ImageLabel::fillAdjacentColor
 * @param pt
 * @param oldColor
 */
void ImageLabel::fillAdjacentColor(QPoint pt, QColor oldColor)
{
    QStack<QPoint> stack;
    stack.push(pt);
    while (stack.size() > 0)
    {
        QPoint point = stack.pop();
        int x = point.x();
        int y = point.y();
        if(img->pixel(x,y) == oldColor.rgb())
        {
            for(int left = x-1; left < x+pixelWidth-1; left++)
            {
                for(int top = y-1; top < y+pixelWidth-1; top++)
                {
                    img->setPixel(left, top, color.rgba());
                }
            }
            stack.push(QPoint(x + pixelWidth, y));
            stack.push(QPoint(x - pixelWidth, y));
            stack.push(QPoint(x, y + pixelWidth));
            stack.push(QPoint(x, y - pixelWidth));
        }
    }
}

/**
 * Updates the current canvas window to the new selected frame Image.
 * @brief ImageLabel::updateCanvasToNewImage
 * @param image
 */
void ImageLabel::updateCanvasToNewImage(QImage* image)
{
    pxmap = new QPixmap();
    this->img = image;
    pxmap->convertFromImage(*this->img);
    setPixmap(QPixmap::fromImage(*img));
}

/**
 * Detects a change in the canvas and saves for later possible undo.
 * Only allows for 10 undos.
 * @brief Spritemon::detectCanvasChange
 * @param oldImage
 */
void ImageLabel::detectCanvasChange(QImage oldImage)//need to set up emit!
{
    QImage* recentImage = new QImage(oldImage);//hold a copy of the image
    //Only 10 undo's are allowed
    if(undoList.size() >= 20)
    {
        undoList.removeFirst();
    }
    undoList.append(recentImage);
    redoList.clear();//watch out for possible error if empty
}


/**
 * Detects the button that was pressed on the canvas. Handles undo, redo, and clear canvas.
 * @brief ImageLabel::detectCanvasButton
 * @param selectedButton
 */
void ImageLabel::detectCanvasButton(QString selectedButton)
{
    if(selectedButton.compare("undo") == 0)
    {
        undo();
    }
    else if(selectedButton.compare("redo") == 0)
    {
        redo();
    }
    else if(selectedButton.compare("clear") == 0)
    {
        clearCanvas();
    }
}

/**
 * Reverts the most recent changes to the canvas and display the previous frame image.
 * @brief ImageLabel::undo
 */
void ImageLabel::undo()
{
    if(undoList.size() > 1)
    {
        redoList.append(undoList.last());
        undoList.removeLast();
        QImage* updatedImage = new QImage(*undoList.last());
        img = updatedImage;
        this->pxmap = new QPixmap();
        pxmap->convertFromImage(*this->img);
        this->setPixmap(QPixmap::fromImage(*img));
    }
    else if(undoList.size() == 1)
    {
        redoList.append(undoList.last());
        QImage* updatedImage = new QImage(*undoList.last());
        img = updatedImage;
        this->pxmap = new QPixmap();
        pxmap->convertFromImage(*this->img);
        this->setPixmap(QPixmap::fromImage(*img));
        undoList.removeLast();
    }
    emit updateModelWithNewFrame(img);
}

/**
 * Provides the most recent fram removed from the undo method.
 * @brief ImageLabel::redo
 */
void ImageLabel::redo()
{
    if(redoList.size() > 0)
    {
        QImage* updatedImage = new QImage(*redoList.last());
        img = updatedImage;
        this->pxmap = new QPixmap();
        pxmap->convertFromImage(*this->img);
        this->setPixmap(QPixmap::fromImage(*img));
        undoList.append(redoList.last());
        redoList.removeLast();
    }
    emit updateModelWithNewFrame(img);
}

/**
 * Removes all the pixels from the current canvas and prsents a fresh empty canvas.
 * @brief ImageLabel::clearCanvas
 */
void ImageLabel::clearCanvas()
{
    clear();
    img->fill(Qt::transparent);
    frame = this->img;
    redoList.clear();
    undoList.clear();
    emit updateModelWithNewFrame(img);
    detectCanvasChange(*img);
}

/**
 * Re-initializes the undo/redo list.
 * @brief ImageLabel::clearUndoRedoList
 * @param image
 */
void ImageLabel::clearUndoRedoList(QImage* image)
{
    redoList.clear();
    undoList.clear();
    detectCanvasChange(*image);
}

/**
 * Slot that receives and updates the canvas grid
 * @brief ImageLabel::updateFrameWidth
 * @param size
 */
void ImageLabel::updateFrameWidth(int size)
{
    numberOfPixels = size;
    pixelWidth = sizeX/numberOfPixels;
}


