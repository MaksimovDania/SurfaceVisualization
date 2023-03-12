#include "matrix.h"

#include <cstring>

Matrix::Matrix(const double *data) {
    memcpy(&_data, data, 16 * sizeof(double));
}

Point Matrix::transform(const Point &point) const {
    double x = point.x * _data[0][0] + point.y * _data[0][1] + point.z * _data[0][2] + _data[0][3];
    double y = point.x * _data[1][0] + point.y * _data[1][1] + point.z * _data[1][2] + _data[1][3];
    double z = point.x * _data[2][0] + point.y * _data[2][1] + point.z * _data[2][2] + _data[2][3];

    return { x, y, z };
}
