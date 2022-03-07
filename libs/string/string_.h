//
// Created by DeriliyDarkNight on 06.03.2022.
//

#include "../algorithms/algorithms.h"
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef MAIN_C_STRING__H
#define MAIN_C_STRING__H

// возвращает длину строки begin
size_t strlen_(char *begin);

// возвращает указатель
// на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end. Если символ не найден, возвращается значение end.
char *find(char *begin, const char *end, int ch);

// возвращает адресс первого символа отличного от пробела в строке begin если возможно,
// иначе возвращает адрес первого ноль-символа
char *findNonSpace(char *begin);

// возвращает адресс первого символа пробела в строке begin если возможно,
// иначе возвращает адрес первого ноль-символа
char *findSpace(char *begin);

// возвращает адресс первого, с конца, символа отличного от пробела в строке begin если возможно,
// иначе возвращает адрес первого ноль-символа
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает адресс первого, с конца, символа пробела в строке begin если возможно,
// иначе возвращает адрес первого ноль-символа
char *findSpaceReverse(char *rbegin, const char *rend);

// возвращает значение истина если строки str1 и str2 равны, иначе "ложь"
int strcmp_(const char *str1, const char *str2);

// записывает по адресу beginDestination фрагмент памяти,
// начиная с адреса beginSource до endSource.
// Возвращает указатель на следующий свободный фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
// заканчивая endSource, удовлетворяющие функции-предикату f. Функция возвращает указатель на
// следующий свободный для записи фрагмент в памяти
char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f. Функция возвращает
// значение beginDestination по окончанию работы функции
char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

int isSpaceNoInString(int symbol);

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

#define MAX_STRING_SIZE 100
# define MAX_N_WORDS_IN_STRING 100
# define MAX_WORD_SIZE 20
char stringBuffer[MAX_STRING_SIZE + 1];

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

#endif //MAIN_C_STRING__H
