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

int strcmp_(char *lhs, char *rhs){
    if (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs)
        return strcmp_(++lhs, ++rhs);

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    long long distance = endSource - beginSource;
    memcpy(beginDestination, beginSource, distance);

    return beginDestination + distance;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (*beginSource != '\0' && beginSource != endSource)
        if (f(*(beginSource++)))
            memcpy(beginDestination++, beginSource - 1, sizeof(char));

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource)
        if (f(*(rbeginSource--)))
            memcpy(beginDestination++, rbeginSource + 1, sizeof(char));

    return beginDestination;
}
