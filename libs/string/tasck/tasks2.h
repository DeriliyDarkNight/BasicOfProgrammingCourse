//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASKS2_H
#define MAIN_C_TASKS2_H

#include "../string_.h"

//task2 Сократить количество пробелов между словами данного предложения до
//одного
void removeExtraSpaces(char *s) {
    char *begin = s;
    char *dst = begin;
    char last = *begin;

    while (*begin != '\0') {
        if (*begin != last || last != ' ')
            *dst++ = *begin;

        last = *begin++;
    }
    if (last == ' ')
        dst--;

    *dst = '\0';
}

void test_removeExtraSpaces_() {
    char s[100] = " de   r i  l  iy";
    removeExtraSpaces(s);
    ASSERT_STRING("de r i l iy", s);
}

void test_removeExtraSpaces_allSpace() {
    char s[100] = " ";
    removeExtraSpaces(s);
    ASSERT_STRING(" ", s);
}

void test_removeExtraSpaces_emptyString() {
    char s[100] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_();
    test_removeExtraSpaces_allSpace();
    test_removeExtraSpaces_emptyString();
}

#endif //MAIN_C_TASKS2_H
