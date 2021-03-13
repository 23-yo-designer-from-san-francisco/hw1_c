#include <stdlib.h>
#include <stdio.h>
#include <io.h>

double **input(size_t *arr_size) {
    char input[100];

    printf("Введите размер массива>");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Неверный ввод\n");
        return NULL;
    }

    if (sscanf(input, "%zu", arr_size) != 1) {
        printf("Неверный ввод\n");
        return NULL;
    }

    if (*arr_size < 3) {
        printf("В массиве должно не менее 3 элементов\n");
        return NULL;
    }

    double *x = (double*)malloc(sizeof(double) * (*arr_size));
    double *y = (double*)malloc(sizeof(double) * (*arr_size));

    for (size_t i = 0; i < *arr_size; ++i) {
        printf("Введите координату X %zu точки>", i+1);
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Неверный ввод\n");
            return NULL;
        }

        if (sscanf(input, "%lf", &x[i]) != 1) {
            printf("Неверный ввод\n");
            return NULL;
        }

        printf("Введите координату Y %zu точки>", i+1);
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Неверный ввод\n");
            return NULL;
        }

        if (sscanf(input, "%lf", &y[i]) != 1) {
            printf("Неверный ввод\n");
            return NULL;
        }
    }

    double **arrays = (double **)malloc(sizeof(double **) * DIMENSIONS);

    arrays[0] = x;
    arrays[1] = y;

    return arrays;
}

void print(size_t **result) {
    printf("Треугольник с наибольшей площадью можно составить из точек с номерами: ");
    for (size_t i = 0; i < RESULT_ARR_SIZE; ++i) {
        printf("%zu ", *result[i]);
    }
    printf("\n");
}

void free_input(double **data) {
    free(data[0]);
    free(data[1]);
    free(data);
}
