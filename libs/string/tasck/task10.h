//
// Created by DeriliyDarkNight on 08.03.2022.
//

#ifndef MAIN_C_TASK10_H
#define MAIN_C_TASK10_H

#include "../string_.h"

// task10 Преобразовать строку, изменив порядок следования слов в строке на обратный
void reverseWord(char *string) {
    *copy(string, getEndOfString(string), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);
    char *copyS = string;
    for (int i = _bag.size - 1; i >= 0; --i) {
        string = copy(_bag.words[i].begin, _bag.words[i].end, string);
        *string++ = ' ';
    }
    if (string != copyS)
        --string;
    *string = '\0';
}

void test_reverseWord_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    reverseWord(s);
    ASSERT_STRING("", s);
}

void test_reverseWord_oneWord() {
    char s[MAX_STRING_SIZE] = "false";
    reverseWord(s);
    ASSERT_STRING("false", s);
}

void test_reverseWord_twoWords() {
    char s[MAX_STRING_SIZE] = "false code";
    reverseWord(s);
    ASSERT_STRING("code false", s);
}

void test_reverseWord_manyWords() {
    char s[MAX_STRING_SIZE] = "my name is JoJo";
    reverseWord(s);
    ASSERT_STRING("JoJo is name my", s);
}

void test_task10() {
    test_reverseWord_emptyString();
    test_reverseWord_oneWord();
    test_reverseWord_twoWords();
    test_reverseWord_manyWords();
}

#endif //MAIN_C_TASK10_H
