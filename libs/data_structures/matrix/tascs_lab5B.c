//
// Created by DeriliyDarkNight on 23.02.2022.
//

#include "tascs_lab5B.h"
#include "../../algorithms/array/array.h"
#include <malloc.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

void sortRowsByMaxElement(matrix m) {
    selectionSortRowsMatrixByRowCriteria(m, getMax);
}

void sortColsByMinElement(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    matrix c = getMemMatrix(m1.nRows, m1.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            c.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++)
                c.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return c;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        matrix z = mulMatrices(*m, *m);
        swap_(m, &z, sizeof(matrix));
        freeMemMatrix(z);
    }
}

void transposeIfMatrixHasEqualSumOfRows(matrix m) {
    long long rowSums[m.nRows];
    for (int row = 0; row < m.nRows; ++row) {
        rowSums[row] = getSum(m.values[row], m.nCols);
    }
    if (!isUnique(rowSums, m.nRows))
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m3 = mulMatrices(m1, m2);
    bool res = isEMatrix(m3);
    freeMemMatrix(m3);
    return res;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int nDiagonals = m.nRows + m.nCols - 1;
    int diagonalMaxes[nDiagonals];
    for (int i = 0; i < nDiagonals; ++i) {
        diagonalMaxes[i] = INT32_MIN;
    }
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            position elementPos = {i, j};
            int element = getElementByPosition(m, elementPos);
            int diagonalIndex = getDiagonalIndex(elementPos, m);
            if (element > diagonalMaxes[diagonalIndex])
                diagonalMaxes[diagonalIndex] = element;
        }
    }
    return getSum(diagonalMaxes, nDiagonals) - diagonalMaxes[m.nRows - 1];
}

int getDiagonalIndex(position pos, matrix m) {
    return abs(pos.rowIndex - pos.colIndex - (m.nRows - 1));
}

int getMinInArea(matrix m) {
    int diagonal[m.nCols];
    size_t size = 0;
    position max = getMaxValuePos(m);
    int x = max.rowIndex;
    int y = max.colIndex;
    int min = getElementByPosition(m, max);
    while (x != 0) {
        x--;
        getArrayFromLeftDiagonal(m, (position) {x, y}, diagonal, &size);
        int diagonalMin = getMin(diagonal, size);
        if (diagonalMin < min)
            min = diagonalMin;

        getArrayFromRightDiagonal(m, (position) {x, y}, diagonal, &size);
        diagonalMin = getMin(diagonal, size);
        if (diagonalMin < min)
            min = diagonalMin;
    }
    return min;
}

void getArrayFromLeftDiagonal(matrix m, position pos, int *array, size_t *size) {
    *size = 0;
    int x = pos.rowIndex;
    int y = pos.colIndex;
    while (x >= 0 && y != m.nCols) {
        array[*size] = m.values[x][y];
        *size += 1;
        y++;
        x--;
    }
}

void getArrayFromRightDiagonal(matrix m, position pos, int *array, size_t *size) {
    *size = 0;
    int x = pos.rowIndex;
    int y = pos.colIndex;
    while (x >= 0 && y >= 0) {
        array[*size] = m.values[x][y];
        *size += 1;
        y--;
        x--;
    }
}

float getDistance(int *a, int n) {
    float sumOfSquares = 0;
    for (int i = 0; i < n; ++i) {
        sumOfSquares += powf(a[i], 2);
    }
    return sqrtf(sumOfSquares);
}

void sortByDistances(matrix m) {
    selectionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    if (*(long long *) pa == *(long long *) pb)
        return 0;
    else if (*(long long *) pa > *(long long *) pb)
        return 1;
    else
        return -1;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int uniqueElements = n > 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            uniqueElements++;
    }
    return uniqueElements;
}

int countEqClassesByRowsSum(matrix m) {
    long long rowSums[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        rowSums[i] = getSum(m.values[i], m.nCols);
    }
    int nClasses = countNUnique(rowSums, m.nRows);
    return nClasses;
}

int getNSpecialElement(matrix m) {
    int nSpecialElements = 0;
    for (int i = 0; i < m.nRows; ++i) {
        long long rowSum = getSum(m.values[i], m.nCols);
        long long max = getMax(m.values[i], m.nCols);
        nSpecialElements += rowSum - max < max;
    }
    return nSpecialElements;
}

void swapPenultimateRow(matrix m) {
    position minPos = getMinValuePos(m);
    int colWithMin[m.nRows];
    getRowFromColumn(m, minPos.colIndex, colWithMin);
    for (int i = 0; i < m.nRows; ++i) {
        m.values[m.nRows - 2][i] = colWithMin[i];
    }
}

bool isNonDescendingSorted(const int *a, int n) {
    bool isSorted = true;
    size_t index = 1;
    while (isSorted && index < n) {
        isSorted = a[index] >= a[index - 1];
        index++;
    }
    return isSorted;
}

bool hasAllNonDescendingRows(matrix m) {
    bool isSorted = true;
    size_t index = 0;
    while (isSorted && index < m.nRows) {
        isSorted = isNonDescendingSorted(m.values[index], m.nCols);
        index++;
    }
    return isSorted;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int nSorted = 0;
    for (int matrix = 0; matrix < nMatrix; ++matrix) {
        nSorted += hasAllNonDescendingRows(ms[matrix]);
    }
    return nSorted;
}

int countValues(const int *a, int n, int value){
    int nValues = 0;
    for (int i = 0; i < n; ++i) {
        nValues+= a[i] == value;
    }
    return nValues;
}

int countZeroRows(matrix m){
    int zeroRows = 0;
    for (int row = 0; row < m.nRows; ++row) {
        zeroRows += countValues(m.values[row], m.nCols, 0) == m.nCols;
    }
    return zeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix){
    int nZeroRows[nMatrix];
    for (int matrix = 0; matrix < nMatrix; ++matrix) {
        nZeroRows[matrix] = countZeroRows(ms[matrix]);
    }

    int max = getMax(nZeroRows, nMatrix);

    for (int i = 0; i < nMatrix; ++i) {
        if (nZeroRows[i] == max)
            outputMatrix(ms[i]);
    }
}

void swapRowsWithMinAndMax(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}

int getMaxNegative(const int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }

    return -max;
}

int getMinNegative(const int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }

    return -min;
}

int getMaxAbsoluteOfArray(int *a, int size){
    int absoluteMax = abs(a[0]);
    for (int i = 0; i < size; ++i) {
        int absolute  = abs(a[i]);
        if (absolute > absoluteMax)
            absoluteMax = absolute;
    }
    return absoluteMax;
}

int getMaxAbsoluteOfMatrix(matrix m){
    int absoluteMax = abs(m.values[0][0]);
    for (int i = 0; i < m.nRows; ++i) {
        int absolute  = getMaxAbsoluteOfArray(m.values[i], m.nCols);
        if (absolute > absoluteMax)
            absoluteMax = absolute;
    }
    return absoluteMax;
}

void printMatricesWithMinOfMaxOfAbsolute(matrix *ms, int size){
    int absoluteMax[size];
    for (int matrix = 0; matrix < size; ++matrix) {
        absoluteMax[matrix] = getMaxAbsoluteOfMatrix(ms[matrix]);
    }

    int min = getMin(absoluteMax, size);

    for (int i = 0; i < size; ++i) {
        if (absoluteMax[i] == min)
            outputMatrix(ms[i]);
    }
}
