//
// Created by DeriliyDarkNight on 06.03.2022.
//

#include <string.h>
#include "string_.h"
#include <ctype.h>
#include <stdio.h>

#define ASSERT_STRING ( expected , got ) assertString ( expected , got , \
 __FILE__ , __FUNCTION__ , __LINE__ )

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

char *find(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch) {
        begin++;
    }

    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin)) {
        begin++;
    }

    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0') {
        begin++;
    }

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

int strcmp_(char *str1, char *str2) {
    return strcmp(str1, str2) == 0;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource + 1);

    return beginDestination + (endSource - beginSource) + 1;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            memcpy(beginDestination, beginSource, sizeof(char));
            beginDestination++;
        }
        beginSource++;
    }
    return beginSource;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource + 1 != rendSource) {
        if (f(*rbeginSource)) {
            memcpy(beginDestination, rbeginSource, sizeof(char));
            beginDestination++;
        }
        rbeginSource--;
    }
    return beginDestination;
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

char *getEndOfString(char *begin) {
    while (*begin != '\0') {
        begin++;
    }

    return begin;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}
