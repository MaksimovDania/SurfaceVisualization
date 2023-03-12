#include "filereader.h"

#include "exception.h"
#include "utils.h"
#include <memory>

#define MATRIX_SIZE 16

FileReader::FileReader() :
    _fd(nullptr, fclose),
    _text(nullptr, free),
    _scene({})
{
}

Scene FileReader::read(const char *path, int *width, int *height, int **raw)
{
    if (*path == '\0')
        throw new FileException();

    FILE *fd = fopen(path, "r");
    if (fd == nullptr)
        throw new FileException();

    FILE* old = _fd.release();
    if(old != nullptr)
        fclose(old);
    _fd.reset(fd);

    realRead();
    int _width = getWidth();
    int _height = count(_text.get(), '\n');
    int *_raw = (int *) malloc(_width * _height * sizeof(int));
    if (_raw == nullptr)
        throw new MemoryAllocationError();

    modifyText();

    char *p = _text.get();
    for (int i = 0; i < _width * _height; i++) {
        _raw[i] = strtol(p, &p, 10);
        p++;
    }

    *width = _width;
    *height = _height;
    *raw = _raw;

    return _scene;
}

void FileReader::realRead()
{
    size = MATRIX_SIZE;
    int limit = size;
    char *text = (char *) calloc(size, sizeof(char));
    if (text == nullptr)
        throw new MemoryAllocationError();

    _text.release();
    _text.reset(text);

    char *cursor = _text.get();
    while (fgets(cursor, limit, _fd.get())) {
        int newSize = strlen(_text.get());
        if (newSize == size - 1)
            expand();

        cursor = _text.get() + newSize;
        limit = size - newSize;
    }

    if (!feof(_fd.get()))
        throw new FileException();
}

void FileReader::expand()
{
    size *= 2;
    char *text2 = (char *) realloc(_text.get(), size * sizeof(char));
    if (text2 == nullptr)
        throw new MemoryAllocationError();

    _text.release();
    _text.reset(text2);
}

int FileReader::getWidth()
{
    char *newLine = (char *) strchr(_text.get(), '\n');
    *newLine = '\0';
    int width = count(_text.get(), ',') + 1;
    *newLine = '\n';
    return width;
}

void FileReader::modifyText()
{
    char *p = _text.get();
    while ((p = (char *) strchr(p, '\n')))
        *p = ',';
}
