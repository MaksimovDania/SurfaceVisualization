#include "scene.h"

Scene::Scene(const std::vector<Figure> &figures) :
    _figures(figures)
{
}

const std::vector<Figure>& Scene::figures() const
{
    return _figures;
}

void Scene::transform(const Matrix &matrix)
{
    for (Figure &figure : _figures)
        figure.transform(matrix);
}
