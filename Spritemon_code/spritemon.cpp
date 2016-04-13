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

#include "spritemon.h"
#include <QObject>
#include <QColor>
#include <QList>
#include <QImage>
#include <QFileDialog>

/**
 * Data model for Spritemon.
 * Keeps a collection of frames as Images.
 * @brief Spritemon::Spritemon
 * @param parent
 */
Spritemon::Spritemon(QObject *parent) : QObject(parent)
{
    currentFrame = -1;
    spriteWidth = 64;

    //Initialize the previousColor list
    previousColors.push_front(QColor(255,0,0));
    previousColors.push_front(QColor(0,0,255));
    previousColors.push_front(QColor(0,255,0));
    previousColors.push_front(QColor(255,255,0));
    previousColors.push_front(QColor(0,255,255));
    previousColors.push_front(QColor(255,0,255));
    previousColors.push_front(QColor(0,0,0));

    //sent signal to update GUI
    emit previousColorArrayUpdated(previousColors);
}

/**
 * Adds the selected color to the previousColors list.
 * Only allows 7 items int the list.
 * Emits signal telling the view to update gui.
 * @brief Spritemon::updateRecentColorArray
 * @param color
 */
void Spritemon::updateRecentColorArray(QColor color)
{
    previousColors.push_front(color);

    //keeps list at no more than 7 colors.
    while(previousColors.size() > 7)
    {
        previousColors.removeLast();
    }
   emit previousColorArrayUpdated(previousColors);
}

/**
 * Creates a transparent frame and adds it to the frames list
 * @brief Spritemon::addFrame
 */
void Spritemon::addFrame()
{
    QImage* image = new QImage(448, 448, QImage::Format_ARGB32);
    QColor color(0,0,0,0);
    image->fill(color);
    frames.append(image);
}

/**
 * Helper method for saving a file.
 * Grabs each individual red, green,
 * blue, and alpha values from each pixel
 * and appends it to a string.
 * @brief Spritemon::getOutputStream
 * @return
 */
QString Spritemon::getOutputStream()
{
    QString output = "";
    int pixelWidth = 448/spriteWidth;

    for(QImage *img : frames)
    {
        for(int y = 1 ; y <= 448-pixelWidth+1; y = y+pixelWidth)
        {
            for(int x = 1 ; x <= 448-pixelWidth+1; x = x+pixelWidth)
            {
                QRgb fill = QRgb(img->pixel(x, y));
                if(fill != 0000)
                {
                    QColor color = QColor(fill);
                    output += "" + QString::number(color.red());
                    output += " " + QString::number(color.green());
                    output += " " + QString::number(color.blue());
                    output += " " + QString::number(color.alpha());
                    output += " ";
                } else
                {
                    //transparency value
                    output += "0 0 0 0 ";
                }
            }
            output += "\n";
        }
    }
    return output;
}


