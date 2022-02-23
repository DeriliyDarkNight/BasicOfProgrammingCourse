//
// Created by DeriliyDarkNight on 23.02.2022.
//

#ifndef MAIN_C_TASCS_LAB5B_H
#define MAIN_C_TASCS_LAB5B_H

#include "matrix.h"

// сортирует строки матрицы m по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix m);

// сортирует столбцы матрицы m по неубыванию наименьших элементов столбцов
void sortColsByMinElement(matrix m);

// если матрица m симметричная, то заменяет её квадратом
void getSquareOfMatrixIfSymmetric(matrix *m);


#endif //MAIN_C_TASCS_LAB5B_H
