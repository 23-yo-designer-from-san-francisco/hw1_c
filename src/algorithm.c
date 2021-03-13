#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "algorithm.h"

#define MIN_ARR_SIZE 3
#define RESULT_ARR_SIZE 3

size_t **get_max_triangle(const double *x, const double *y, const size_t ARR_SIZE) {
    if (!x || !y || ARR_SIZE < MIN_ARR_SIZE) {
        return NULL;
    }
    double max = 0;

    size_t **result = (size_t **)malloc(sizeof(size_t *) * 3);

    size_t *point1 = (size_t*)malloc(sizeof(size_t));
    size_t *point2 = (size_t*)malloc(sizeof(size_t));
    size_t *point3 = (size_t*)malloc(sizeof(size_t));

    if (!result || !point1 || !point2 || !point3) {
        printf("Memory allocation error");
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

void free_result(size_t **result) {
    if (result) {
        for (size_t i = 0; i < RESULT_ARR_SIZE; ++i) {
            free(result[i]);
        }
        free(result);
    }
}


