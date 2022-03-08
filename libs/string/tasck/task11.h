//
// Created by DeriliyDarkNight on 08.03.2022.
//

#ifndef MAIN_C_TASK11_H
#define MAIN_C_TASK11_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore) {
    WordDescriptor word;
    char *begin = s;
    WordDescriptor nextWord;
    if (!getWord(begin, &word))
        return EMPTY_STRING;
    else if (find(word.begin, word.end, 'A') != word.end || find(word.begin, word.end, 'a') != word.end)
        return FIRST_WORD_WITH_A;
    while (getWord(begin, &nextWord)) {
        if (find(nextWord.begin, nextWord.end, 'A') != nextWord.end ||
            find(nextWord.begin, nextWord.end, 'a') != nextWord.end) {
            *beginWordBefore = word.begin;
            *endWordBefore = word.end;
            return WORD_FOUND;
        }
        begin = word.end;
        word = nextWord;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}


void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert (getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);

    char s2[] = " ABC";
    assert (getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert (getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);

    char got1[MAX_WORD_SIZE];
    copy(beginWord, endWord, got1);
    got1[endWord - beginWord] = '\0';
    ASSERT_STRING ("BC", got1);

    char s4[] = "B Q WE YR OW IUWR ";
    assert (getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) ==
            NOT_FOUND_A_WORD_WITH_A);

    char s5[] = "B Q WE YR OWO IUAR ";
    assert (getWordBeforeFirstWordWithA(s5, &beginWord, &endWord) == WORD_FOUND);

    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING ("OWO", got);
}

#endif //MAIN_C_TASK11_H
