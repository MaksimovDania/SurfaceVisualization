#ifndef VERTEX_H
#define VERTEX_H

#include "point.h"
#include "matrix.h"

// вершина
class Vertex {
private:
    Point _position;

public:
    Vertex(const Point &position);

    const Point& position() const;
    void transform(const Matrix &matrix);
};

#endif
