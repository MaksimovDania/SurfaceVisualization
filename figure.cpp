#include "figure.h"

Figure::Figure(const vector<Vertex> &vertices, const vector<Edge> &edges) :
    _vertices(vertices),
    _edges(edges)
{
}

const vector<Vertex>& Figure::vertices() const
{
    return _vertices;
}

const vector<Edge>& Figure::edges() const
{
    return _edges;
}

void Figure::transform(const Matrix &matrix)
{
    for (Vertex &vertex : _vertices)
        vertex.transform(matrix);
    for (Edge &edge : _edges)
        edge.transform(matrix);
}

