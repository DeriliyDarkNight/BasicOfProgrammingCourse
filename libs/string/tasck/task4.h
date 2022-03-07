//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASK4_H
#define MAIN_C_TASK4_H

#include "../string_.h"

// task4 Преобразовать строку, заменяя каждую цифру соответствующим ей числом
//пробелов
void replacesNumbersWithSpaces(char *s) {
    char *endSource = getEndOfString(s);
    char *stringBufferStart = stringBuffer;
    char *endOfStringBuffer = copy(s, endSource, stringBufferStart);
    *endOfStringBuffer = '\0';
    while (*stringBufferStart != '\0') {
        if (isalpha(*stringBufferStart)) {
            *s++ = *stringBufferStart;
        } else if (isdigit(*stringBufferStart)) {
            while (*stringBufferStart - 48 > 0) {
                *s++ = ' ';
                (*stringBufferStart)--;
            }
        }
        ++stringBufferStart;
    }
}

void test_replacesNumbersWithSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    replacesNumbersWithSpaces(s);
    ASSERT_STRING("", s);
}

void test_replacesNumbersWithSpaces_letter() {
    char s[MAX_STRING_SIZE] = "reter";
    replacesNumbersWithSpaces(s);
    ASSERT_STRING("reter", s);
}

void test_replacesNumbersWithSpaces_digits() {
    char s[MAX_STRING_SIZE] = "111";
    replacesNumbersWithSpaces(s);
    ASSERT_STRING("   ", s);
}

void test_replacesNumbersWithSpaces_lettersAndDigits() {
    char s[MAX_STRING_SIZE] = "re2te1";
    replacesNumbersWithSpaces(s);
    ASSERT_STRING("re  te ", s);
}

void test_replacesNumbersWithSpaces_task4() {
    test_replacesNumbersWithSpaces_emptyString();
    test_replacesNumbersWithSpaces_letter();
    test_replacesNumbersWithSpaces_digits();
    test_replacesNumbersWithSpaces_lettersAndDigits();
}

#endif //MAIN_C_TASK4_H
