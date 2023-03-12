#ifndef UTILS_H
#define UTILS_H

//#include <cstring>

void free2D(char **strings, int size);
void free3D(char ***strings, int size, int subsize);
int count(const char *str, char divider);
void swap(double *first, double *second);
void sort(double *numbers, int size);
int maxInt(int *numbers, int size);
int minInt(int *numbers, int size);

#endif
