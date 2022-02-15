//
// Created by DeriliyDarkNight on 26.12.2021.
//

#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "../../algorithms/array/array.h"
#include "unordered_array_set.h"

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

unordered_array_set unordered_array_set_create_from_array(const int *a,
                                                          size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrinkToFit(&set);
    return set;
}

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool unordered_array_set_isEqual(unordered_array_set set1,
                                 unordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert (set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

unordered_array_set unordered_array_set_union(
        unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set set3 = unordered_array_set_create_from_array(set1.data, set1.size);
    for (size_t j = 0; j < set2.size; ++j) {
        size_t indexElement = linearSearch_(set1.data, set1.size, set2.data[j]);
        if (indexElement == -1)
            unordered_array_set_insert(&set3, set2.data[j]);
    }
    return (unordered_array_set) set3;
}

unordered_array_set unordered_array_set_intersection(
        unordered_array_set set1, unordered_array_set set2
) {
    unordered_array_set set3 = unordered_array_set_create(set1.capacity);
    for (size_t i = 0; i < set2.size; ++i) {
        size_t indexElementSet2 = linearSearch_(set1.data, set1.size, set2.data[i]);
        if (indexElementSet2 != -1)
            unordered_array_set_insert(&set3, set2.data[i]);
    }
    return (unordered_array_set) set3;
}

unordered_array_set unordered_array_set_difference(
        unordered_array_set set1, unordered_array_set set2
) {
    for (size_t i = 0; i < set2.size; ++i) {
        size_t indexElementSet2 = linearSearch_(set1.data, set1.size, set2.data[i]);
        if (indexElementSet2 != -1)
            deleteByPosSaveOrder_(set1.data, &set1.size, indexElementSet2);
    }
    return (unordered_array_set) set1;
}

unordered_array_set unordered_array_set_symmetricDifference(
        unordered_array_set set1, unordered_array_set set2
) {
    unordered_array_set set3 = unordered_array_set_difference(set1, set2);
    unordered_array_set set4 = unordered_array_set_difference(set2, set1);
    return (unordered_array_set) unordered_array_set_union(set3, set4);
}

void unordered_array_set_print(unordered_array_set set) {
    outputArray_(set.data, set.size);
}

void unordered_array_set_deleteElement(
        unordered_array_set *set, int value) {
    size_t indexDeleteElement = linearSearch_(set->data, set->size, value);
    assert(indexDeleteElement != -1);
    deleteByPosSaveOrder_(set->data, &set->size, indexDeleteElement);
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}