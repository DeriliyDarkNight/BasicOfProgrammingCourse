#include <assert.h>
#include <ctype.h>
#include "libs/string/string_.h"
#include "libs/string/tasck/tascs1.h"
#include "libs/string/tasck/tasks2.h"
#include "libs/string/tasck/tasks3.h"
#include "libs/string/tasck/task4.h"
#include "libs/string/tasck/task5.h"
#include "libs/string/tasck/task6.h"
#include "libs/string/tasck/task8.h"
#include "libs/string/tasck/task9.h"
#include "libs/string/tasck/task10.h"
#include "libs/string/tasck/task11.h"
#include "libs/string/tasck/task12.h"

void test_findNonSpace_noSymbols() {
    char string[] = "";
    assert(findNonSpace(string) == string);
}

void test_findNonSpace_allSpaces() {
    char string[] = "\t\n ";
    assert(findNonSpace(string) == string + 3);
}

void test_findNonSpace_text() {
    char string[] = "\t \t \n Hiro \n as ";
    assert(findNonSpace(string) == string + 6);
}

void test_findSpace_firstSpace() {
    char string[] = "\t\n ";
    assert(findSpace(string) == string);
}

void test_findSpace_noSpace() {
    char string[] = "";
    assert(findSpace(string) == string);
}

void test_findSpace_text() {
    char string[] = "Want to go";
    assert(findSpace(string) == string + 4);
}

void test_findNonSpaceReverse_noSpace() {
    char string[] = "aoaoaoaoN";
    assert(findNonSpaceReverse(string + (strlen_(string) - 1),
                               string) == string + strlen_(string) - 1);
}

void test_findNonSpaceReverse_noSymbols() {
    char string[] = "\n";
    assert(findNonSpaceReverse(string + (strlen_(string) - 1),
                               string) == string);
}

void test_findNonSpaceReverse_text() {
    char string[] = "Hello, world!";
    assert(findNonSpaceReverse(string + (strlen_(string) - 1),
                               string) == string + strlen_(string) - 1);
}

void test_findSpaceReverse_emptyString() {
    char string[] = "";
    assert(findSpaceReverse(string + (strlen_(string)),
                            string) == string);
}

void test_findSpaceReverse_text() {
    char string[] = "I swap to bad";
    assert(findSpaceReverse(string + (strlen_(string) - 1),
                            string) == string + (strlen_(string) - 4));
}

void test_findSpaceReverse_firstSpace() {
    char string[] = "Yeeees \n";
    assert(findSpaceReverse(string + (strlen_(string) - 1),
                            string) == string + (strlen_(string) - 1));
}

void test_strcmp_equalStrings() {
    char string1[] = "Hello, \t world";
    char string2[] = "Hello, \t world";

    assert(strcmp_(string1, string2) == 0);
}

void test_strcmp_differentStrings() {
    char string1[] = "Hello, \t world";
    char string2[] = "aoaoaoaoa";

    assert(strcmp_(string1, string2) < 0);
}

void test_strcmp_differentString2() {
    char string1[] = "ccc";
    char string2[] = "CCC";

    assert(strcmp_(string1, string2) > 0);
}

void test_copy_emptyString() {
    char string[] = "";
    char answerString[strlen_(string)];
    copy(string, string + strlen_(string) + 1,
         answerString);

    assert(strcmp_(string, answerString) == 0);
}

void test_copy_text() {
    char string[] = "Hello, world!";
    char answerString[strlen_(string)];
    copy(string, string + strlen_(string) + 1,
         answerString);

    assert(strcmp_(string, answerString) == 0);
}

void test_copyIf_emptyString() {
    char string[] = "";
    char string2[strlen_(string)];
    char answerString[] = "";
    copyIf(string, string + strlen_(string) + 1,
           string2, isSpaceNoInString);

    assert(strcmp_(string2, answerString) == 0);
}

void test_copyIf_digit() {
    char string[] = "12345";
    char string2[strlen_(string)];
    char answerString[] = "12345";;
    copyIf(string, string + strlen_(string) + 1,
           string2, isdigit);

    assert(strcmp_(string2, answerString) == 0);
}

void test_copyIfReverse_digit() {
    char string[] = "12345";
    char string2[strlen_(string)];
    copyIfReverse(string + strlen_(string) - 1, string - 1,
                  string2, isdigit);
    char answerString[] = "54321";

    assert(strcmp_(string2, answerString) == 0);
}

void test_findNonSpace() {
    test_findNonSpace_noSymbols();
    test_findNonSpace_allSpaces();
    test_findNonSpace_text();
}

void test_findSpace() {
    test_findSpace_firstSpace();
    test_findSpace_noSpace();
    test_findSpace_text();
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_noSpace();
    test_findNonSpaceReverse_noSymbols();
    test_findNonSpaceReverse_text();
}

void test_findSpaceReverse() {
    test_findSpaceReverse_emptyString();
    test_findSpaceReverse_firstSpace();
    test_findSpaceReverse_text();
}

void test_strcmp() {
    test_strcmp_equalStrings();
    test_strcmp_differentStrings();
    test_strcmp_differentString2();
}

void test_copy() {
    test_copy_emptyString();
    test_copy_text();
}

void test_copyIf() {
    test_copyIf_emptyString();
    test_copyIf_digit();
}

void test_copyIfReverse() {
    test_copyIfReverse_digit();
}

void tests_library_string() {
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_copyIfReverse();
    test_findNonSpace();
    test_findSpace();
    test_strcmp();
    test_copyIf();
    test_copy();
}

void tests_tasks() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToStartString();
    test_replacesNumbersWithSpaces();
    test_replace();
    test_areWordsOrdered();
    test_countWordsPalindromes();
    test_alternatingWordsInString();
    test_reverseWord();
    testAll_getWordBeforeFirstWordWithA();
    test_lastWordInFirstStringIsInSecondString();
}

void tests() {
    tests_library_string();
    tests_tasks();
}

int main() {
    tests();
    return 0;
}