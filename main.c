#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "libs/string/string_.h"

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
    char string[] = "Want to sleep";
    assert(findSpace(string) == string + 4);
}

void test_findNonSpaceReverse_noSpace() {
    char string[] = "aofnanfowN";
    assert(findNonSpaceReverse(string + (strlen_(string) - 1),
                               string) == string + strlen_(string) - 1);
}

void test_findNonSpaceReverse_noSymbols() {
    char string[] = "\n";
    assert(findNonSpaceReverse(string + (strlen_(string) - 1),
                               string) == string);
}

void test_findNonSpaceReverse_text() {
    char string[] = "Hello, bed!";
    assert(findNonSpaceReverse(string + (strlen_(string) - 1),
                               string) == string + strlen_(string) - 1);
}

void test_findSpaceReverse_emptyString() {
    char string[] = "";
    assert(findSpaceReverse(string + (strlen_(string)),
                            string) == string);
}

void test_findSpaceReverse_text() {
    char string[] = "I want to eat";
    assert(findSpaceReverse(string + (strlen_(string) - 1),
                            string) == string + (strlen_(string) - 4));
}

void test_findSpaceReverse_firstSpace() {
    char string[] = "Nooooo \n";
    assert(findSpaceReverse(string + (strlen_(string) - 1),
                            string) == string + (strlen_(string) - 1));
}

void test_strcmp_equalStrings() {
    char string1[] = "Hello, \t world";
    char string2[] = "Hello, \t world";

    assert(strcmp(string1, string2) == 0);
}

void test_strcmp_differentStrings() {
    char string1[] = "Hello, \t world";
    char string2[] = "ksfsafjpj";

    assert(strcmp(string1, string2) < 0);
}

void test_strcmp_differentString2() {
    char string1[] = "aaa";
    char string2[] = "AAA";

    assert(strcmp(string1, string2) > 0);
}

void test_copy_emptyString() {
    char string[] = "";
    char answerString[strlen_(string)];
    copy(string, string + strlen_(string) + 1,
         answerString);

    assert(strcmp(string, answerString) == 0);
}

void test_copy_text() {
    char string[] = "Hello, world!";
    char answerString[strlen_(string)];
    copy(string, string + strlen_(string) + 1,
         answerString);

    assert(strcmp(string, answerString) == 0);
}

void test_copyIf_emptyString() {
    char string[] = "";
    char string2[strlen_(string)];
    char answerString[] = "";
    copyIf(string, string + strlen_(string) + 1,
           string2, !isspace);

    assert(strcmp(string2, answerString) == 0);
}

void test_copyIf_text() {
    char string[] = "Hello, world!";
    char string2[strlen_(string)];
    char answerString[] = "Hello,world!";;
    copyIf(string, string + strlen_(string) + 1,
           string2, isNonSpace);

    assert(strcmp(string2, answerString) == 0);
}

void test_copyIfReverse_emptyString() {
    char string[0] = "";
    char string2[strlen_(string)];
    char answerString[] = "";
    copyIfReverse(string + strlen_(string) + 1, string,
                  string2, isNonSpace);

    assert(strcmp(string2, answerString) == 0);
}

void test_copyIfReverse_text() {
    char string[] = "hello";
    char string2[strlen_(string)];
    copyIfReverse(string + strlen_(string) - 1, string - 1,
                  string2, isNonSpace);
    char answerString[] = "olleh";

    assert(strcmp(string2, answerString) == 0);
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
    test_copyIf_text();
}

void test_copyIfReverse() {
    test_copyIfReverse_emptyString();
    test_copyIfReverse_text();
}

void tests() {
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_copyIfReverse();
    test_findNonSpace();
    test_findSpace();
    test_strcmp();
    test_copyIf();
    test_copy();
}

int main() {
    tests();
    return 0;
}