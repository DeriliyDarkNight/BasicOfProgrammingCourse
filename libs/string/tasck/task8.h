//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASK8_H
#define MAIN_C_TASK8_H

#include "../string_.h"

bool isPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return false;
        begin++;
        end--;
    }
    return true;
}

size_t countWordsPalindromes(char *s) {
    char *endString = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPalindromes = 0;

    char *commaPosition = find(beginSearch, endString, ',');
    bool lastComma = *commaPosition == '\0' && endString - beginSearch != 0;
    while (*commaPosition != '\0' || lastComma) {
        beginSearch = findNonSpace(beginSearch);

        countPalindromes += isPalindrome(beginSearch, commaPosition);

        beginSearch = commaPosition + 1;

        if (lastComma)
            break;

        commaPosition = find(beginSearch, endString, ',');
        lastComma = *commaPosition == '\0';
    }
    return countPalindromes;
}

void test_countWordsPalindromes_emptyString() {
    char s[] = "";
    assert(countWordsPalindromes(s) == 0);
}

void test_countWordsPalindromes_onePalindrome() {
    char s[] = "dered";
    assert(countWordsPalindromes(s) == 1);
}

void test_countWordsPalindromes_twoPalindrome() {
    char s[] = "dered,reder";
    assert(countWordsPalindromes(s) == 2);
}

void test_countWordsPalindromes_onePalindromeFromTwo() {
    char s[] = "dered,derer";
    assert(countWordsPalindromes(s) == 1);
}

void test_countWordsPalindromes_oneSymbol() {
    char s[] = "a";
    assert(countWordsPalindromes(s) == 1);
}

void test_howManyWordsPalindromes_task8() {
    test_countWordsPalindromes_emptyString();
    test_countWordsPalindromes_onePalindrome();
    test_countWordsPalindromes_twoPalindrome();
    test_countWordsPalindromes_onePalindromeFromTwo();
    test_countWordsPalindromes_oneSymbol();
}

#endif //MAIN_C_TASK8_H
