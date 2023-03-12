#include "facade.h"

#include "matrixbuilder.h"
#include "utils.h"
#include <cstdlib>

struct Points{
    Point from;
    Point to;
};
void addToVectors (vector<Vertex>& vertices, vector<Edge>& edges, shared_ptr<Points> point);

Facade::Facade(shared_ptr<FileReaderBase> fileReader, shared_ptr<SceneDrawerBase> sceneDrawer) :
    _fileReader(fileReader),
    _sceneDrawer(sceneDrawer),
    _scene({}),
    _normalization(),
    _translation({}),
    _rotation({}),
    _scale({ 1.0f, 1.0f, 1.0f }),
    _width(0),
    _height(0),
    _raw(nullptr),
    _rawMin(0),
    _rawMax(0)
{
}

Facade::~Facade()
{
    if (_raw)
        free(_raw);
}

void Facade::load(const char *path)
{
    if (_raw)
        free(_raw);

    _fileReader->read(path, &_width, &_height, &_raw);
    _rawMin = minInt(_raw, _width * _height);
    _rawMax = maxInt(_raw, _width * _height);
    generate();
}

void Facade::normalization(const Normalization &normalization)
{
    _normalization = normalization;
    generate();
}

void Facade::translation(double x, double y, double z)
{
    _translation = { x, y, z };
    generate();
}

void Facade::rotation(double x, double y, double z)
{
    _rotation = { x, y, z };
    generate();
}

void Facade::scale(double x, double y, double z)
{
    _scale = { x, y, z };
    generate();
}

void Facade::draw() const
{
    _sceneDrawer->draw(_scene);
}

void Facade::generate()
{
    if (_raw == nullptr)
        return;

    vector<Vertex> vertices;
    vector<Edge> edges;

    for (int y = 0; y < _height - 1; y++) {
        for (int x = 0; x < _width - 1; x++) {
            Point from = getPoint(x, y); // берем точку
            Point toHorizontal = getPoint(x + 1, y); // берем следующую горизонтальную точку
            Point toVertical = getPoint(x, y + 1); // берем следующую вертикальную точку
            vertices.push_back(from); //добавляем точку в вектор вершин
            edges.push_back({ from, toHorizontal }); //добавляем край горизонтальной точки в вектор краёв
            edges.push_back({ from, toVertical }); //добавляем край вертикальной точки в вектор краёв
        }
    }

    func(vertices, edges);

    vertices.push_back(getPoint(_width - 1, _height - 1));

    _scene = Scene({ Figure(vertices, edges) });
    _scene.transform(MatrixBuilder::translation(_width * _normalization.dx * -0.5f, _height * _normalization.dy * -0.5f, 0.0f));
    _scene.transform(MatrixBuilder::scale(_scale));
    _scene.transform(MatrixBuilder::rotation(_rotation));
    _scene.transform(MatrixBuilder::translation(_translation));
}

void Facade::func (vector<Vertex>& vertices, vector<Edge>& edges){
    shared_ptr<Points> point = shared_ptr<Points>(new Points());
    for (int x = 0; x < _width - 1; x++) {
        point->from = getPoint(x, _height - 1);
        point->to = getPoint(x + 1, _height - 1);
        addToVectors(vertices, edges, point);
    }

    for (int y = 0; y < _height - 1; y++) {
        point->from = getPoint(_width - 1, y);
        point->to = getPoint(_width - 1, y + 1);
        addToVectors(vertices, edges, point);
    }
}

void addToVectors (vector<Vertex>& vertices, vector<Edge>& edges, shared_ptr<Points> point){
    vertices.push_back(point->from);
    edges.push_back({ point->from, point->to });
}

Point Facade::getPoint(int x, int y) const{
    double a = _normalization.min;
    double b = _normalization.max;
    return {
        x * _normalization.dx, //x
        y * _normalization.dy, //y
        a + (_raw[y * _width + x] - _rawMin) * (b - a)/ (double) (_rawMax - _rawMin) //z
    };
}
