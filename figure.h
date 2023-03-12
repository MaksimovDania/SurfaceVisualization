#ifndef FIGURE_H
#define FIGURE_H

#include "edge.h"
#include <vector>
using namespace std;

class Figure {
private:
    vector<Vertex> _vertices;
    vector<Edge> _edges;

public:
    Figure(const vector<Vertex> &vertices, const vector<Edge> &edges);

    const vector<Vertex>& vertices() const;
    const vector<Edge>& edges() const;
    void transform(const Matrix &matrix);
};

#endif
