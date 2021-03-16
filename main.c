/*Составить программу нахождения треугольника с максимальной площадью среди всех, которые можно построить,
соединив произвольные три точки из заданного массива.
Алгоритм оформить в виде функции, получающей на вход два массива указателей на X — и Y-координаты точек.
На выход функция должна вернуть массив указателей из трех элементов
на номера точек, образующих найденный треугольник.*/

#include <stdlib.h>

#include "algorithm.h"
#include "io.h"

#define INPUT_ERROR 300
#define CALCULATION_ERROR 302

int main() {
    size_t arr_size;

    double **data = input(&arr_size);
    if (!data) {
        return INPUT_ERROR;
    }

    size_t **result = get_max_triangle(data[0], data[1], arr_size);

    if (!result) {
        return CALCULATION_ERROR;
    }

    print(result);

    free_input(data);
    free_result(result);
}
