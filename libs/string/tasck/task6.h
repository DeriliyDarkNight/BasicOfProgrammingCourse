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

void test_areWordsOrdered_emptyString() {
    char s[] = "";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_oneWord() {
    char s[] = "search";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered_notOrderedString() {
    char s[] = "search me";
    assert(areWordsOrdered(s) == false);
}

void test_areWordsOrdered_twoWord() {
    char s[] = "search search";
    assert(areWordsOrdered(s) == true);
}

void test_areWordsOrdered() {
    test_areWordsOrdered_emptyString();
    test_areWordsOrdered_oneWord();
    test_areWordsOrdered_notOrderedString();
    test_areWordsOrdered_twoWord();
}

#endif //MAIN_C_TASK6_H
