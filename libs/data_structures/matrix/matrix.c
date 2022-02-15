//
// Created by DeriliyDarkNight on 15.02.2022.
//

#include "matrix.h"
#include <malloc.h>
#include "../../algorithms/array/array.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

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

