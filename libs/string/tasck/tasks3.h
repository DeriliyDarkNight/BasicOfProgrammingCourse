//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASKS3_H
#define MAIN_C_TASKS3_H

#include "../string_.h"

// task3 Преобразовать строку таким образом, чтобы цифры каждого слова были
//перенесены в начало слова без изменения порядка следования их в слове,
//буквы перенести в конец слова
void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 stringBuffer);
    char *recPosition = copyIf(stringBuffer,
                               endStringBuffer,
                               word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartString(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

void test_digitToStartString_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    digitToStartString(s);
    ASSERT_STRING("", s);
}

void test_digitToStartString_digitAndWord() {
    char s[MAX_STRING_SIZE] = "te212";
    digitToStartString(s);
    ASSERT_STRING("212te", s);
}

void test_digitToStartString_twoDigitAndTwoWord() {
    char s[MAX_STRING_SIZE] = "te212 et121";
    digitToStartString(s);
    ASSERT_STRING("212te 121et", s);
}

void test_digitToStartString_digitAndSpaceWord() {
    char s[MAX_STRING_SIZE] = "212 te";
    digitToStartString(s);
    ASSERT_STRING("212 te", s);
}

void test_digitToStartString() {
    test_digitToStartString_emptyString();
    test_digitToStartString_digitAndWord();
    test_digitToStartString_twoDigitAndTwoWord();
    test_digitToStartString_digitAndSpaceWord();
}

#endif //MAIN_C_TASKS3_H
