#include "normalization.h"

Normalization::Normalization(double _min, double _max, double _dx, double _dy) :
    min(_min),
    max(_max),
    dx(_dx),
    dy(_dy)
{
}

Normalization::Normalization() :
    Normalization(0.0f, 1.0f, 1.0f, 1.0f)
{
}
