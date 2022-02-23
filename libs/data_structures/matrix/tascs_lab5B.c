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
