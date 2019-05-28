#include "painter.h"

static const qreal FOOD_RADIUS = 3;

Point::Point(qreal x, qreal y)
{
    setPos(x, y);
    setData(GD_Type, GO_Food);
}

QRectF Point::boundingRect() const
{
    return QRectF(-TILE_SIZE,    -TILE_SIZE,
                   TILE_SIZE * 2, TILE_SIZE * 2 );
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);

    painter->restore();
}

QPainterPath Point::shape() const
{
    QPainterPath p;
    p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}


static int PONINT_SIZE = 10;

QList<QPointF> tail;

QPainterPath shape()
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    path.addRect(QRectF(0, 0, PONINT_SIZE, PONINT_SIZE));

//    foreach (QPointF p, tail) {
//        QPointF itemp = mapFromScene(p);
//        path.addRect(QRectF(itemp.x(), itemp.y(), PONINT_SIZE, PONINT_SIZE));
//    }

    return path;
}

void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->fillPath(shape(), Qt::yellow);
    painter->restore();
}
