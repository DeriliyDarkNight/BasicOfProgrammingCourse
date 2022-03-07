//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASCS1_H
#define MAIN_C_TASCS1_H

#include "../string_.h"

// tasks 1 удалить из строки все пробельные символы
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_spaceBetween() {
    char s[] = " n o 3 3 3 n o ";
    removeNonLetters(s);
    ASSERT_STRING("no333no", s);
}

void test_removeNonLetters_noSpaces() {
    char s[] = "no333no";
    removeNonLetters(s);
    ASSERT_STRING("no333no", s);
}

void test_removeNonLetters_allSpaces() {
    char s[] = "   ";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_task1() {
    test_removeNonLetters_spaceBetween();
    test_removeNonLetters_noSpaces();
    test_removeNonLetters_allSpaces();
}

#endif //MAIN_C_TASCS1_H
