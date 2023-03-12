#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H

#include "matrix.h"

class MatrixBuilder {
public:
    static Matrix translation(double x, double y, double z);
    static Matrix translation(const Point &translation);
    static Matrix rotation(double x, double y, double z);
    static Matrix rotation(const Point &rotation);
    static Matrix scale(double x, double y, double z);
    static Matrix scale(const Point &scale);

    MatrixBuilder() = delete;
};

#endif
