#ifndef FACADE_H
#define FACADE_H

#include <memory>
#include "filereaderbase.h"
#include "scenedrawerbase.h"
#include "normalization.h"
#include "scene.h"

using namespace std;

class Facade {
private:
    shared_ptr<FileReaderBase> _fileReader;
    shared_ptr<SceneDrawerBase> _sceneDrawer;
    Scene _scene;
    Normalization _normalization;
    Point _translation;
    Point _rotation;
    Point _scale;
    int _width;
    int _height;
    int *_raw;
    int _rawMin;
    int _rawMax;

    Point getPoint(int x, int y) const;
    void generate();

public:
    Facade(shared_ptr<FileReaderBase> fileReader, shared_ptr<SceneDrawerBase> sceneDrawer);
    ~Facade();

    void func (vector<Vertex>& vertices, vector<Edge>& edges);
    void load(const char *path);
    void normalization(const Normalization &normalization);
    void translation(double x, double y, double z);
    void rotation(double x, double y, double z);
    void scale(double x, double y, double z);
    void draw() const;
};

#endif
