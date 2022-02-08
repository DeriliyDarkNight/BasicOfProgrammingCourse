//
// Created by DeriliyDarkNight on 08.02.2022.
//

#include "vector.h"

void check_memory(const int *data) {
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vector createVector(const size_t n) {
    int *data = NULL;
    if (n > 0) {
        data = (int *) malloc(n * sizeof(int));
        check_memory(data);
    }
    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->capacity = newCapacity;
    if (newCapacity < v->size) {
        v->size = newCapacity;
    }
    if (v->capacity > 0) {
        v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
        check_memory(v->data);
    } else
        v->data = NULL;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    reserve(v, 0);
}

bool isEmpty(const vector v) {
    return v.size == 0;
}

bool isFull(const vector v) {
    return v.size == v.capacity;
}

int getVectorValue(const vector v, const size_t i) {
    return v.data[i];
}

bool isZeroVector(vector v) {
    return v.capacity == 0;
}

void pushBack(vector *v, int x) {
    if (isZeroVector(*v)) {
        reserve(v, v->capacity + 1);
        v->data[v->size++] = x;
    } else if (isFull(*v)) {
        reserve(v, v->capacity * 2);
        v->data[v->size++] = x;
    } else
        v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmpty(*v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    reserve(v, v->capacity - 1);
}

