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

#ifndef SPRITEMON_H
#define SPRITEMON_H

#include <QObject>
#include <QColor>
#include <QList>
#include <QString>
#include <QImage>

class Spritemon : public QObject
{
public:
    explicit Spritemon(QObject *parent = 0);

    int currentFrame;
    int spriteWidth;
    QList<QColor> previousColors;
    QList<QImage*> frames;
    void addFrame();
    QString getOutputStream();

signals:
    void previousColorArrayUpdated(QList<QColor>);

public slots:
    void updateRecentColorArray(QColor);

private:
    Q_OBJECT

};

#endif // SPRITEMON_H

