#ifndef SCENE_H
#define SCENE_H

#include "figure.h"
using namespace std;

class Scene {
private:
    vector<Figure> _figures;

public:
    Scene(const vector<Figure> &figures);

    const vector<Figure>& figures() const;
    void transform(const Matrix &matrix);
};

#endif
