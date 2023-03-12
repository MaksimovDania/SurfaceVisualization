#ifndef SCENEDRAWERBASE_H
#define SCENEDRAWERBASE_H

#include "scene.h"

class SceneDrawerBase
{
public:
    virtual void draw(const Scene &scene) const = 0; //класс абстрактный, его наследник - Scene Drawer
};

#endif
