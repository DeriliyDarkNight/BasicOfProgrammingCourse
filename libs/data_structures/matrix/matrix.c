//
// Created by DeriliyDarkNight on 15.02.2022.
//

#include "matrix.h"
#include <malloc.h>
#include "../../algorithms/array/array.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <memory.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; ++i)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    assert(nMatrices > 0);
    for (size_t i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int columns = 0; columns < m.nRows; columns++)
        for (int rows = 0; rows < m.nCols; rows++)
            scanf("%d", &(m.values[columns][rows]));
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int matrix = 0; matrix < nMatrices; matrix++) {
        inputMatrix(ms[matrix]);
    }
}

void outputMatrix(matrix m) {
    for (int columns = 0; columns < m.nRows; columns++) {
        printf("\n| ");

        for (int rows = 0; rows < m.nCols; rows++)
            printf("%d | ", (m.values[columns][rows]));
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int matrix = 0; matrix < nMatrices; matrix++) {
        outputMatrix(ms[matrix]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int row = 0; row < m.nRows; ++row) {
        swap_(&m.values[row][j1], &m.values[row][j2], sizeof(int));
    }
}

void selectionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int criteriaArray[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        criteriaArray[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; ++i) {
        int min = i;
        for (int j = i; j < m.nRows; j++) {
            if (criteriaArray[j] < criteriaArray[min])
                min = j;
        }
        swap_(&criteriaArray[min], &criteriaArray[i], sizeof(int));
        swapRows(m, i, min);
    }
}

void getRowFromColumn(matrix m, size_t pos, int *array) {
    for (int i = 0; i < m.nRows; ++i)
        array[i] = m.values[i][pos];
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int criteriaArray[m.nCols];
    int column[m.nRows];
    for (int i = 0; i < m.nCols; ++i) {
        getRowFromColumn(m, i, column);
        criteriaArray[i] = criteria(column, m.nRows);
    }
    for (int i = 0; i < m.nCols; ++i) {
        int min = i;
        for (int j = i; j < m.nCols; j++) {
            if (criteriaArray[j] < criteriaArray[min])
                min = j;
        }
        swap_(&criteriaArray[min], &criteriaArray[i], sizeof(int));
        swapColumns(m, i, min);
    }
}

void selectionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float criteriaArray[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        criteriaArray[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; ++i) {
        int min = i;
        for (int j = i; j < m.nRows; j++) {
            if (criteriaArray[j] < criteriaArray[min])
                min = j;
        }
        swap_(&criteriaArray[min], &criteriaArray[i], sizeof(float));
        swapRows(m, i, min);
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows == m2.nRows && m1.nCols == m2.nCols) {
        bool isEqual = true;
        size_t y = 0;
        while (isEqual && y < m1.nRows) {
            isEqual = memcmp(m1.values[y], m2.values[y], sizeof(int) * m1.nCols) == 0;
            y++;
        }
        return (bool) isEqual;
    }
    return (bool) false;
}

bool isEMatrix(matrix m) {
    bool isE = true;
    size_t y = 0;
    while (isE && y < m.nRows) {
        size_t x = 0;
        while (isE && x < m.nCols) {
            isE = (bool) (m.values[y][x] == 1);
            x++;
        }
        y++;
    }
    return (bool) isE;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m)) {
        return false;
    } else {
        bool isSymmetric = true;
        size_t y = 0;
        while (isSymmetric && y < m.nRows) {
            size_t x = (y + 1);
            while (isSymmetric && x < m.nCols) {
                isSymmetric = (bool) (m.values[y][x] == m.values[x][y]);
                x++;
            }
            y++;
        }
        return (bool) isSymmetric;
    }
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = i + 1; j < m.nCols; ++j) {
            swap_(&m.values[i][j], &m.values[j][i], sizeof(int));
        }
    }
}

int getElementByPosition(matrix m, position pos) {
    return m.values[pos.rowIndex][pos.colIndex];
}

position getMinValuePos(matrix m) {
    position min = (position) {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            position current = (position) {i, j};
            if (getElementByPosition(m, current) < getElementByPosition(m, min))
                min = current;
        }
    }
    return min;
}

position getMaxValuePos(matrix m) {
    position max = (position) {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            position current = (position) {i, j};
            if (getElementByPosition(m, current) > getElementByPosition(m, max))
                max = current;
        }
    }
    return max;
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}