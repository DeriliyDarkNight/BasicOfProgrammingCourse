//
// Created by DeriliyDarkNight on 26.12.2021.
//

#include <stdio.h>
#include <assert.h>
#include "bitset.h"

bitset bitset_create(unsigned setMaxValue) {
    assert(setMaxValue < 32);
    return (bitset) {0, setMaxValue};
}

bool bitset_in(bitset set, unsigned value) {
    unsigned valueBit = (set.values >> value) & 1;
    return valueBit == 1;
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values && set1.maxValue == set2.maxValue;
}

void bitset_insert(bitset *set, unsigned value) {
    assert(value < set->maxValue);
    set->values = set->values | ((unsigned) (1) << value);
}

bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & ~set2.values, set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

bitset bitset_complement(bitset set) {
    unsigned unusedBit = 31 - set.maxValue;
    return (bitset) {(~set.values << unusedBit) >> unusedBit, set.maxValue};
}

void bitset_deleteElement(bitset *set, unsigned value) {
    assert(value < set->maxValue);
    set->values = set->values & ~((unsigned)(1) << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bool bitset_isSubset(bitset subset, bitset set) {
    assert(subset.maxValue <= set.maxValue);
    for (unsigned i = 0; i <= subset.maxValue; ++i) {
        unsigned valueSubsetBit = subset.values & i;
        unsigned valueSetBit = set.values & i;
        if (valueSubsetBit != valueSetBit)
            return false;
    }
    return true;
}

void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}
