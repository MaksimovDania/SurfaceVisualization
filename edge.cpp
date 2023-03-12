#include "edge.h"

Edge::Edge(const Vertex &begin, const Vertex &end) :
    _begin(begin),
    _end(end)
{
}

const Vertex& Edge::begin() const{
    return _begin;
}

const Vertex& Edge::end() const{
    return _end;
}

void Edge::transform(const Matrix &matrix){
    _begin.transform(matrix);
    _end.transform(matrix);
}
