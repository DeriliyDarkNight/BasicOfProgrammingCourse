//
// Created by DeriliyDarkNight on 07.03.2022.
//

#ifndef MAIN_C_TASK7_H
#define MAIN_C_TASK7_H

#include "../string_.h"

//task7 Вывести слова данной строки в обратном порядке по одному в строке экрана.
void printReverse(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);
    char *begin = s;
    for (int i = 0; i < _bag.size; i++) {
        *copyReverse(_bag.words[i].end - 1, _bag.words[i].begin - 1, begin) = '\0';
        printf("%s \n", begin);
    }
}

void test_task7() {
    char s[] = "hello word!";
    printReverse(s);
}

#endif //MAIN_C_TASK7_H
