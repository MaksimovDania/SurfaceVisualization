#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>

using namespace std;

class MemoryAllocationError : public exception
{
public:
    MemoryAllocationError() = default;

    virtual const char * what() const noexcept override;
};

class FileException : public exception
{
public:
    FileException() = default;

    virtual const char * what() const noexcept override;
};

class PixmapException: public exception
{
public:
    PixmapException() = default;

    virtual const char * what() const noexcept override;
};

#endif
