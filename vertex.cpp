#include "vertex.h"

Vertex::Vertex(const Point &position) :
    _position(position)
{
}

const Point& Vertex::position() const {
    return _position;
}

void Vertex::transform(const Matrix &matrix) { // трансформирует точку в новый базис
    _position = matrix.transform(_position);
}
