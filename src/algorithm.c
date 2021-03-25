#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "algorithm.h"

#define MIN_ARR_SIZE 3
#define RESULT_ARR_SIZE 3

size_t *get_max_triangle(const double *x, const double *y, const size_t ARR_SIZE) {
    if (!x || !y || ARR_SIZE < MIN_ARR_SIZE) {
        return NULL;
    }
    double max = 0;

    size_t *result = (size_t *)malloc(sizeof(size_t *) * RESULT_ARR_SIZE);
    if (!result) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }

    for (size_t i = 0; i < ARR_SIZE - 2; ++i) {
        for (size_t j = i; j < ARR_SIZE - 1; ++j) {
            for (size_t k = j; k < ARR_SIZE; ++k) {
                double area = fabs(
                        (x[i] - x[j])
                        * (y[i] - y[k])
                        - (x[i] - x[k])
                        * (y[i] - y[j])) / 2.0;
                if (area > max) {
                    max = area;
                    result[0] = i;
                    result[1] = j;
                    result[2] = k;
                }
            }
        }
    }

    return result;
}
