//
// Created by DeriliyDarkNight on 26.12.2021.
//

#include "algorithms.h"

#define ZERO_SYMBOL 48

void inputArray(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

void outputArray(int *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", a[i]);
    }
}

int isEvenSymbol(int a) {
    if(a > 48 && a < 57)
        return (a - 48) % 2 == 0;
    return 0;
}

char *getEndOfString (char *s) {
    while (*s != '\0')
        s++;
    return s;
}