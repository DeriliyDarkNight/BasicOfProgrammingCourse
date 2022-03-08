//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASK5_H
#define MAIN_C_TASK5_H

#include "../string_.h"

// task5 Заменить все вхождения слова 𝑤1 на слово 𝑤2
void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }

    WordDescriptor curWord;
    while (getWord(readPtr, &curWord)) {
        recPtr = copy(readPtr, curWord.begin, recPtr);
        if (areWordsEqual(curWord, word1) == 0) {
            recPtr = copy(word2.begin, word2.end, recPtr);
        } else {
            recPtr = copy(curWord.begin, curWord.end, recPtr);
        }
        readPtr = curWord.end;
    }

    *recPtr = '\0';
}

void test_replace_emptyString1() {
    char s[MAX_STRING_SIZE] = "";
    char *word1 = "";
    char *word2 = "";
    replace(s, word1, word2);
    ASSERT_STRING("", s);
}

void test_replace_emptyString2() {
    char s[MAX_STRING_SIZE] = "";
    char *word1 = "eee";
    char *word2 = "www";
    replace(s, word1, word2);
    ASSERT_STRING("", s);
}

void test_replace_firstWordReplace() {
    char s[MAX_STRING_SIZE] = "ww wer ww";
    char *word1 = "ww";
    char *word2 = "wer";
    replace(s, word1, word2);
    ASSERT_STRING("wer wer wer", s);
}

void test_replace_notReplaceWordFromString() {
    char s[MAX_STRING_SIZE] = "hello world hello";
    char *word1 = "aaa";
    char *word2 = "bye";
    replace(s, word1, word2);
    ASSERT_STRING("hello world hello", s);
}

void test_replace() {
    test_replace_emptyString1();
    test_replace_emptyString2();
    test_replace_firstWordReplace();
    test_replace_notReplaceWordFromString();
}

#endif //MAIN_C_TASK5_H
