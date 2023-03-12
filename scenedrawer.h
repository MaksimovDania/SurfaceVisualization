#ifndef SCENEDRAWER_H
#define SCENEDRAWER_H

#include "exception.h"
#include "scenedrawerbase.h"
#include <QLabel>

class SceneDrawer : public SceneDrawerBase //наследование
{
private:
    QLabel *_canvas;

    static void drawLine(QPainter &painter, const Edge &edge, QColor color);
    static void drawPoint(QPainter &painter, const Scene &scene);

public:
    SceneDrawer(QLabel *canvas);
    static QColor getMyColor(double param);
    virtual void draw(const Scene &scene) const override; // реализуется абстрактный метод класса SceneDrawerBase
};

#endif
