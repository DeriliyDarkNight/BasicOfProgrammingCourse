//
// Created by DeriliyDarkNight on 23.02.2022.
//

#include "tascs_lab5B.h"
#include "../../algorithms/array/array.h"
#include <malloc.h>
#include <iso646.h>
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

