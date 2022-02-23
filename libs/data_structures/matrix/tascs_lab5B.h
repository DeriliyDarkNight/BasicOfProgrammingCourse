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

// возвращает сумму максимумов всех псевдодиагонали матрицы m
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

// возвращает порядковый номер диагонали к которой принадлежит pos-тый элемент матрицы m
int getDiagonalIndex(position pos, matrix m);

// заполняет массив array размера size элементами диагонали начинающейся с pos - того элемента по направлению вверх и влево строки матрицы m;
void getArrayFromLeftDiagonal(matrix m, position pos, int *array, size_t *size);

// заполняет массив array размера size элементами диагонали начинающейся с pos - того элемента по направлению вверх и вправо  матрицы m;
void getArrayFromRightDiagonal(matrix m, position pos, int *array, size_t *size);

// возвращает минимальный элемент матрицы m в треугольной области выше максимального элемента
int getMinInArea(matrix m);

#endif //MAIN_C_TASCS_LAB5B_H
