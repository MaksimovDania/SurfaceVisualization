#pragma once

#include "scene.h"

class SceneDrawerBase
{
public:
    virtual void draw(const Scene &scene) const = 0;
};

