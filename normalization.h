#ifndef NORMALIZATION_H
#define NORMALIZATION_H

struct Normalization {
public:
    double min;
    double max;
    double dx;
    double dy;

    Normalization(double min, double max, double dx, double dy);
    Normalization();
};

#endif
