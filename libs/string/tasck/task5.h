//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASK5_H
#define MAIN_C_TASK5_H

#include "../string_.h"

// task5 Заменить все вхождения слова 𝑤1 на слово 𝑤2
bool comparisonWords(char *string, char *word) {
    char *copyString = string;
    char *copyWord = word;
    while (*copyString != ' ' && *copyString != '\0') {
        if (*copyString != *copyWord)
            return false;
        copyString++;
        copyWord++;
    }
    return true;
}

void replacesWord(char *source, WordDescriptor word1, WordDescriptor word2, size_t w2Size) {
    while (w2Size != 0) {
        *source = *word2.begin;
        w2Size--;
    }
    while (word1.end - 1 - word2.begin != 0) {
        *source = ' ';
        word2.begin++;
    }
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }
    if (comparisonWords(readPtr, w1)) {
        replacesWord(recPtr, word1, word2, w2Size);
    }
}

#endif //MAIN_C_TASK5_H
