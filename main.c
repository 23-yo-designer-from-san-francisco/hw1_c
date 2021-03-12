/*Составить программу нахождения треугольника с максимальной площадью среди всех, которые можно построить,
соединив произвольные три точки из заданного массива.
Алгоритм оформить в виде функции, получающей на вход два массива указателей на X — и Y-координаты точек.
На выход функция должна вернуть массив указателей из трех элементов
на номера точек, образующих найденный треугольник.*/

#include <stdio.h>
#include <stdlib.h>

#include "include/algorithm.h"

int main(int argc, char *argv[]) {
    if (argc < 7 || !(argc & 1)) {
        printf("Enter two arrays of the same size\n");
        return -1;
    }

    size_t arr_size = (argc-1)/2;

    double *a = (double*)malloc(sizeof(double)*(arr_size));
    double *b = (double*)malloc(sizeof(double)*(arr_size));

    int half = argc/2;

    for (size_t i = 1; i <= half; ++i) {
        if (!((sscanf(argv[i], "%lf", &a[i-1]) == 1) && (sscanf(argv[i+half], "%lf", &b[i-1]) == 1))) {
            printf("Unknown character in input string\n");
            return -1;
        }
    }

    size_t **result = max_area(a, b, half);

    printf("%zu %zu %zu\n", *result[0]+1, *result[1]+1, *result[2]+1);

    free(a);
    free(b);
    free_result(result);
}

