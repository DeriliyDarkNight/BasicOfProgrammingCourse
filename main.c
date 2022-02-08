//
// Created by DeriliyDarkNight on 08.02.2022.
//

#include <assert.h>
#include "libs/data_structures/vector/vector.h"

void test_createVector1(){
    size_t capacity = 0;
    vector v = createVector(capacity);
    assert(v.data == NULL);
}

void test_createVector2(){
    size_t capacity = 33;
    vector v = createVector(capacity);
    assert(v.data != NULL);
}

void test_createVector(){
    test_createVector1();
    test_createVector2();
}

void test_reserve1(){
    vector v = createVector(33);
    size_t newCapacity = 0;
    reserve(&v, newCapacity);
    assert(v.data == NULL);
}

void test_reserve2(){
    vector v = createVector(33);
    v.size = 17;
    size_t newCapacity = 16;
    reserve(&v, newCapacity);
    assert(v.size == v.capacity);
}

void test_reserve(){
    test_reserve1();
    test_reserve2();
}

void test_pushBack1(){
    vector v = createVector(0);
    pushBack(&v, 6);
    assert(v.data[0] == 6);
    assert(v.size == 1);
    assert(v.capacity == 1);
}

void test_pushBack2(){
    vector v = createVector(2);
    v.size = 2;
    pushBack(&v, 6);
    assert(v.data[2] == 6);
    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_pushBack3(){
    vector v = createVector(4);
    v.size = 2;
    pushBack(&v, 6);
    assert(v.data[2] == 6);
    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_pushBack(){
    test_pushBack1();
    test_pushBack2();
    test_pushBack3();
}

void test_popBack1(){
    vector v = createVector(0);
    pushBack(&v, 11);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 0);
}

void test_popBack(){
    test_popBack1();
}

void test_atVector1(){
    vector v = {(int [3]){1, 2, 3}, 3, 6};
    assert(*atVector(&v, 1) == 2);
}

void test_atVector2(){
    vector v = {(int [3]){1, 2, 3}, 3, 6};
    assert(*atVector(&v, v.size - 1) == 3);
}

void test_atVector(){
    test_atVector1();
    test_atVector2();
}

void test_back1(){
    vector v = {(int [1]){1}, 1, 1};
    assert(*back(&v) == 1);
}

void test_back(){
    test_back1();
}

void test_front1(){
    vector v = {(int [1]){1}, 1, 1};
    assert(*front(&v) == 1);
}

void test_front(){
    test_front1();
}

void test(){
    test_createVector();
    test_reserve();
    test_pushBack();
    test_popBack();
    test_atVector();
    test_back();
    test_front();
}

int main() {
    test();
    return 0;
}
