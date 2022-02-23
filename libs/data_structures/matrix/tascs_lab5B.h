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

// транспонирует матрицу m если среди полных сумм строк нет равных
void transposeIfMatrixHasEqualSumOfRows(matrix m);

// возвращает значение "истина", если матрицы m1 и m2 являются взаимнообратными
bool isMutuallyInverseMatrices(matrix m1, matrix m2);


#endif //MAIN_C_TASCS_LAB5B_H
