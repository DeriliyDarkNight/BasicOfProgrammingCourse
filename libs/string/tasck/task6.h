//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASK6_H
#define MAIN_C_TASK6_H

#include "../string_.h"

// task6 Определить, упорядочены ли лексикографически слова данного предложения
bool areWordsOrdered(char *string) {
    WordDescriptor word1;
    WordDescriptor word2;
    if (getWord(string, &word1)) {
        word2 = word1;
        while (getWord(string, &word1)) {
            if (areWordsEqual(word1, word2) < 0)
                return false;
            word2 = word1;
            string = word1.end;
        }
        return true;
    } else
        return true;
}

void test_areWordsOrdered_stringIsEmpty() {
    char s[] = "";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_oneWord() {
    char s[] = "please";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_NotOrderedString() {
    char s[] = "false op";
    assert(areWordsOrdered(s) == false);
}

void test_areWordsOrdered_TwoWords() {
    char s[] = "false false";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_orderedString() {
    char s[] = "c cc ccc ca cc";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_task6() {
    test_areWordsOrdered_stringIsEmpty();
    test_areWordsOrdered_oneWord();
    test_areWordsOrdered_NotOrderedString();
    test_areWordsOrdered_TwoWords();
    test_areWordsOrdered_orderedString();
}

#endif //MAIN_C_TASK6_H
