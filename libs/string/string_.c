//
// Created by DeriliyDarkNight on 06.03.2022.
//

#include "string_.h"

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, const char *end, const int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs != '\0' && *rhs != '\0') {
        lhs++;
        rhs++;
    }

    return (unsigned char) *lhs - (unsigned char) *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    long long distance = endSource - beginSource;
    memcpy(beginDestination, beginSource, distance);

    return beginDestination + distance;
}

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {
    while (beginSource < endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }

        beginSource++;
    }

    return beginDestination + 1;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (rbeginSource > rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }

        rbeginSource--;
    }

    return beginDestination;
}

int isSpaceNoInString(int symbol) {
    return !isspace(symbol);
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}