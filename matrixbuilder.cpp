#include "matrixbuilder.h"

#include <cmath>

Matrix MatrixBuilder::translation(double x, double y, double z)
{
    double data[16] = {
        1, 0, 0, x,
        0, 1, 0, y,
        0, 0, 1, z,
        0, 0, 0, 1,
    };

    return Matrix(data);
}

Matrix MatrixBuilder::translation(const Point &translation)
{
    return MatrixBuilder::translation(translation.x, translation.y, translation.z);
}

Matrix MatrixBuilder::rotation(double x, double y, double z)
{
    double sinx = sin(x);
    double cosx = cos(x);
    double siny = sin(y);
    double cosy = cos(y);
    double sinz = sin(z);
    double cosz = cos(z);
    double data[16] = {
        cosy * cosz,                      cosy * sinz,                      -siny,       0,
        sinx * siny * cosz - cosx * sinz, sinx * siny * sinz + cosx * cosz, sinx * cosy, 0,
        cosx * siny * cosz + sinx * sinz, cosx * siny * sinz - sinx * cosz, cosx * cosy, 0,
        0,                                0,                                0,           1,
    };

    return Matrix(data);
}

Matrix MatrixBuilder::rotation(const Point &rotation)
{
    return MatrixBuilder::rotation(rotation.x, rotation.y, rotation.z);
}

Matrix MatrixBuilder::scale(double x, double y, double z)
{
    double data[16] = {
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1,
    };
    return Matrix(data);
}

Matrix MatrixBuilder::scale(const Point &scale)
{
    return MatrixBuilder::scale(scale.x, scale.y, scale.z);
}
