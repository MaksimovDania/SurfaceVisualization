#ifndef FILEREADER_H
#define FILEREADER_H

#include "filereaderbase.h"
#include <cstdio>
#include <cstdlib>
#include <memory>
using namespace std;

class FileReader : public FileReaderBase // наследование
{
private:
    unique_ptr<FILE, decltype(*fclose)> _fd;
    unique_ptr<char, decltype(*free)> _text;
    int size;
    Scene _scene;

    void realRead();
    void expand();
    int getWidth();
    void modifyText();

public:
    FileReader();

    virtual Scene read(const char *path, int *width, int *height, int **raw) override; // реализует этот метод из FileReaderBase
};

#endif
