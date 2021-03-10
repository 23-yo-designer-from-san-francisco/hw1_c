//
// Created by test on 10.03.2021.
//

#define ARR_SIZE 11

#include <aio.h>
#include <math.h>

size_t** max_area(double *a, double *b) {
    double max = 0;

    size_t **result = (size_t **)malloc(sizeof(size_t*) * 3);

    size_t *point1 = (size_t*)malloc(sizeof(size_t));
    size_t *point2 = (size_t*)malloc(sizeof(size_t));
    size_t *point3 = (size_t*)malloc(sizeof(size_t));

    for (size_t i = 0; i < ARR_SIZE - 2; ++i) {
        for (size_t j = i; j < ARR_SIZE - 1; ++j) {
            for (size_t k = j; k < ARR_SIZE; ++k) {
                double area = fabs((a[i] - a[j]) * (b[i] - b[k]) - (a[i] - a[k]) * (b[i] - b[j])) / 2.0;
                if (area > max) {
                    max = area;
                    *point1 = i;
                    *point2 = j;
                    *point3 = k;
                }
            }
        }
    }

    result[0] = point1;
    result[1] = point2;
    result[2] = point3;

    return result;
}
