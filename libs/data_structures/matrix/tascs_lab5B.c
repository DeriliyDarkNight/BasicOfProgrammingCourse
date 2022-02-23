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

