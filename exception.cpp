#include "exception.h"

const char* MemoryAllocationError::what() const noexcept{
    return "Memory allocation failed";
}

const char* FileException::what() const noexcept{
    return "Failed to load file";
}

const char* PixmapException::what() const noexcept{
    return "Memory allocation failed with pixmap";
}
