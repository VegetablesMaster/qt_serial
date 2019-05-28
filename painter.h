#ifndef PAINTER_H
#define PAINTER_H

#include "constants.h"

#include<QPainter>
#include<QPainterPath>
#include<QPointF>
#include <QGraphicsItem>

#include <QGraphicsItem>

class Point : public QGraphicsItem
{
public:
    Point(qreal x, qreal y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    QPainterPath shape() const;
};

#endif // PAINTER_H
