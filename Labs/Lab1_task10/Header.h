#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <locale.h>

// Функция для преобразования строки в число в заданной системе счисления
long long convert_string_to_int(const char* str, int base) {
    long long result = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            result = result * base + (str[i] - '0');
        }
        else if (isupper(str[i])) {
            result = result * base + (str[i] - 'A' + 10);
        }
        else {
            printf("Ошибка: Недопустимый символ в строке.\n");
            return LLONG_MIN; // Возвращаем минимальное значение long long в случае ошибки
        }
    }
    return result;
}

// Функция для преобразования числа в строку в заданной системе счисления
char* convert_int_to_string(long long num, int base) {
    // Исправленные строки:
    char* result = (char*)malloc(64); // Приведение типа void* к char*
    if (result == NULL)
    {
        return NULL;
    }
    int i = 0;
    if (num == 0) {
        result[i++] = '0';
    }
    else {
        while (num != 0) {
            int digit = abs(num % base); // Используем abs() для отрицательных чисел
            if (digit < 10) {
                result[i++] = digit + '0';
            }
            else {
                result[i++] = digit - 10 + 'A';
            }
            num /= base;
        }
    }
    result[i] = '\0';
    // Переворачиваем строку
    char* temp = (char*)malloc(i + 1);
    for (int j = 0; j < i; j++) {
        temp[j] = result[i - j - 1];
    }
    temp[i] = '\0';
    free(result);
    return temp;
}