#ifndef MATRIX_H
#define MATRIX_H

#include "point.h"

class Matrix {
private:
    double _data[4][4];

public:
    Matrix(const double *data);

    Point transform(const Point &point) const;
};

#endif
