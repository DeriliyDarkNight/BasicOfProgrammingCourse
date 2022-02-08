//
// Created by DeriliyDarkNight on 08.02.2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#ifndef LB5B_VECTOR_H
#define LB5B_VECTOR_H

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

// изменяет количество
//памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v);

// освобождает память, выделенную под
//неиспользуемые элементы.
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору.
void deleteVector(vector *v);

// возвращает "истина", если вектор v пустой, иначе "ложь".
bool isEmpty(vector v);

// возвращает "истина", если вектор v полный, иначе "ложь".
bool isFull(vector v);

// возвращает i-тый элемент вектора v.
int getVectorValue(vector v, size_t i);

// добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x);

// удаляет последний элемент из вектора v.
void popBack(vector *v);

// возвращает указатель на index-ый элемент вектора v.
int *atVector(vector *v, size_t index);

// возвращает указатель на последний элемент вектора v.
int *back(vector *v);

// возвращает указатель на нулевой элемент вектора v.
int *front(vector *v);

typedef struct vectorVoid {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity;// вместимость вектора
    size_t baseTypeSize;// размер базового типа:
                        // например, если вектор хранит int -
                        // то поле baseTypeSize = sizeof(int)
                        // если вектор хранит float -
                        // то поле baseTypeSize = sizeof(float)
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

#endif
