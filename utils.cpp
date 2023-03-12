#include "utils.h"

#include <cstdlib>
#include <cmath>

void free2D(char **strings, int size)
{
    for (int i = 0; i < size; i++)
        free(strings[i]);
    free(strings);
}

void free3D(char ***strings, int size, int subsize)
{
    for (int i = 0; i < size; i++)
        free2D(strings[i], subsize);
    free(strings);
}

int count(const char *str, char divider)
{
    int count = 0;
    for (const char *p = str; *p; p++) {
        if (*p == divider)
            count++;
    }

    return count;
}

void swap(double *first, double *second)
{
    double tmp = *first;
    *first = *second;
    *second = tmp;
}

void sort(double *numbers, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] != numbers[i] || numbers[i] > numbers[j])
                swap(numbers + i, numbers + j);
        }
    }
}

int maxInt(int *numbers, int size)
{
    int max = numbers[0];
    for (int i = 1; i < size; i++)
        max = fmax(max, numbers[i]);

    return max;
}

int minInt(int *numbers, int size)
{
    int min = numbers[0];
    for (int i = 1; i < size; i++)
        min = fmin(min, numbers[i]);

    return min;
}
