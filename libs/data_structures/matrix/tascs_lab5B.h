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

// возвращает расстояние до начала координат от точки с n координатами находящимися в массиве a
float getDistance(int *a, int n);

// сортирует строки ,содержащие координаты точек, матрицы m по отдалению от начала координат
void sortByDistances(matrix m);

// функция компаратор для qsort возвращающая значение 0 если числа равны, -1 если разность чисел отрицательная, иначе 1
int cmp_long_long(const void *pa, const void *pb);

// возвращает количество элементов в массиве a размера n встречающихся 1 и более раз
int countNUnique(long long *a, int n);

// возвращет количество количество классов эквивалентных строк матрицы m
int countEqClassesByRowsSum(matrix m);

// возвращает количество особых элементов матрицы m (таких что элемент больше суммы всех остальных элементов строки);
int getNSpecialElement(matrix m);

//Заменяет предпоследнюю строку матрицы m первым
//из столбцов, в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix m);

// возвращает значение "истина" если массив упорядочен по невозрастанию, иначе "ложь"
bool isNonDescendingSorted(const int *a, int n);

// возвращает значение "истина" если все строки матрицы m упорядочены по невозрастанию иначе "ложь"
bool hasAllNonDescendingRows(matrix m);

// возвращает количество матриц в массиве ms размера nMatrix все строки которых отсортированы по неубыванию
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

#endif //MAIN_C_TASCS_LAB5B_H
