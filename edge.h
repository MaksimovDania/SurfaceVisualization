#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

// край
class Edge {
private:
    Vertex _begin;
    Vertex _end;

public:
    Edge(const Vertex &begin, const Vertex &end);

    const Vertex& begin() const;
    const Vertex& end() const;
    void transform(const Matrix &matrix);
};

#endif
