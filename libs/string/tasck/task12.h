//
// Created by DeriliyDarkNight on 08.03.2022.
//

#ifndef MAIN_C_TASK12_H
#define MAIN_C_TASK12_H

#include "../string_.h"

// task 12 Даны две строки. Определить последнее из слов первой строки, которое есть
//во второй строке
WordDescriptor lastWordInFirstStringIsInSecondString(char *string1, char *string2) {
    getBagOfWords(&_bag, string1);
    getBagOfWords(&_bag2, string2);
    for (int i = _bag.size - 1; i >= 0; --i) {
        for (int j = 0; j < _bag2.size; ++j) {
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0)
                return _bag.words[i];
        }
    }
    WordDescriptor word = {NULL, NULL};
    return word;
}

void test_lastWordInFirstStringIsInSecondString_emptyString() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString(s1, s2), s3);
    ASSERT_STRING("", s3);
}

void test_lastWordInFirstStringIsInSecondString_foundWord() {
    char s1[MAX_STRING_SIZE] = "replace to string";
    char s2[MAX_STRING_SIZE] = "false f string";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString(s1, s2), s3);
    ASSERT_STRING("string", s3);
}

void test_lastWordInFirstStringIsInSecondString_notFoundWord() {
    char s1[MAX_STRING_SIZE] = "replace to string";
    char s2[MAX_STRING_SIZE] = "false f false";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString(s1, s2), s3);
    ASSERT_STRING("\0", s3);
}

void test_lastWordInFirstStringIsInSecondString_foundWordFirstAndSecond() {
    char s1[MAX_STRING_SIZE] = "replace to string";
    char s2[MAX_STRING_SIZE] = "replace f string";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString(s1, s2), s3);
    ASSERT_STRING("string", s3);
}

void test_lastWordInFirstStringIsInSecondString() {
    test_lastWordInFirstStringIsInSecondString_emptyString();
    test_lastWordInFirstStringIsInSecondString_foundWord();
    test_lastWordInFirstStringIsInSecondString_notFoundWord();
    test_lastWordInFirstStringIsInSecondString_foundWordFirstAndSecond();
}

#endif //MAIN_C_TASK12_H
