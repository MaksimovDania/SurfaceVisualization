#pragma once

#include "scene.h"
#include <cstring>

class FileReaderBase
{
public:
    virtual Scene read(const char *path, size_t *width, size_t *height, int **raw) = 0;
};
