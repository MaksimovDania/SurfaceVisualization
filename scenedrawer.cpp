#include "scenedrawer.h"

#include <QPainter>
#include <iostream>


SceneDrawer::SceneDrawer(QLabel *canvas) :
    _canvas(canvas)
{
}

void SceneDrawer::draw(const Scene &scene) const
{
    QPixmap *pixmap;
    try {
        pixmap = new QPixmap(650, 650);
    } catch (_exception) {
        throw new PixmapException();
    }
    QPainter painter(pixmap);
    painter.fillRect(0, 0, 650, 650, QBrush(QColor(Qt::GlobalColor::white)));
    painter.translate(330, 330);
    painter.setPen(QColor(Qt::GlobalColor::darkGray));
    drawPoint(painter, scene);
    _canvas->setPixmap(*pixmap);
}



void SceneDrawer::drawPoint(QPainter &painter, const Scene &scene)
{
    QColor color;
    QPen pen;
    int sizeOfPoint = 4;
    QBrush br(color);
    Point end;
    for (const Figure &figure : scene.figures()) {
        for (const Edge &edge : figure.edges()) {
            Point begin = edge.begin().position();
            end = edge.end().position();
            Point curPoint = edge.begin().position();
            color = getMyColor(curPoint.z);
            br.setColor(color);
            painter.setBrush(br);
            painter.drawEllipse(begin.x - sizeOfPoint/2.0, begin.y - sizeOfPoint/2.0, sizeOfPoint, sizeOfPoint);
            pen.setColor(Qt::darkGray);
            painter.setPen(pen);
            painter.drawLine(QLineF(begin.x, begin.y, end.x, end.y));
        }
    }
    painter.drawEllipse(end.x - sizeOfPoint/2.0, end.y - sizeOfPoint/2.0, sizeOfPoint, sizeOfPoint);
}

QColor SceneDrawer::getMyColor(double param){
    int minim = 100;
    //int med = 255 - minim + param * 2;
    int current = fmax(0, fmin(255 - minim + param * 2, 255));
    qDebug() << current << param;
    QColor color = QColor(100, current, 255);
    return color;
}
