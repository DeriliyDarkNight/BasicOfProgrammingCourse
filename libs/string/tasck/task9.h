//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASK9_H
#define MAIN_C_TASK9_H

#include "../string_.h"

// task9 Даны две строки. Получить строку, в которой
// чередуются слова первой и второй строки. Если в одной из
// строк число слов больше, чем в другой, то оставшиеся слова этой
// строки должны быть дописаны в строку-результат. В качестве
//разделителя между словами используйте пробел
char *alternatingWordsInString(char *string1, char *string2, char *s) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *stringCopy = s;
    char *beginSearch1 = string1, *beginSearch2 = string2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            s = copy(word1.begin, word1.end, s);
            *s++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            s = copy(word2.begin, word2.end, s);
            *s++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    if (s != stringCopy)
        --s;
    *s = '\0';
    return stringCopy;
}

void test_alternatingWordsInString_emptyString() {
    char s1[] = "";
    char s2[] = "";
    char s3[MAX_STRING_SIZE];
    ASSERT_STRING("", alternatingWordsInString(s1, s2, s3));
}

void test_alternatingWordsInString_oneEmptyString() {
    char s1[] = "woodoo";
    char s2[] = "";
    char s3[MAX_STRING_SIZE];
    ASSERT_STRING("woodoo", alternatingWordsInString(s1, s2, s3));
}

void test_alternatingWordsInString_twoStrings() {
    char s1[] = "magick magick";
    char s2[] = "woodoo woodoo";
    char s3[MAX_STRING_SIZE];
    ASSERT_STRING("magick woodoo magick woodoo", alternatingWordsInString(s1, s2, s3));
}

void test_alternatingWordsInString_manySpaceInTwoString() {
    char s1[] = "  ";
    char s2[] = "  ";
    char s3[MAX_STRING_SIZE];
    ASSERT_STRING("", alternatingWordsInString(s1, s2, s3));
}

void test_alternatingWordsInString() {
    test_alternatingWordsInString_emptyString();
    test_alternatingWordsInString_oneEmptyString();
    test_alternatingWordsInString_twoStrings();
    test_alternatingWordsInString_manySpaceInTwoString();
}

#endif //MAIN_C_TASK9_H
