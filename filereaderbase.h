#ifndef FILEREADERBASE_H
#define FILEREADERBASE_H

#include "scene.h"
#include <cstring>

class FileReaderBase
{
public:
    virtual Scene read(const char *path, int *width, int *height, int **raw) = 0;
    //класс абстрактный, его наследник - file reader
};

#endif
