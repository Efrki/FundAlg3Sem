#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <locale.h>

// ������� ��� �������������� ������ � ����� � �������� ������� ���������
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
            printf("������: ������������ ������ � ������.\n");
            return LLONG_MIN; // ���������� ����������� �������� long long � ������ ������
        }
    }
    return result;
}

// ������� ��� �������������� ����� � ������ � �������� ������� ���������
char* convert_int_to_string(long long num, int base) {
    // ������������ ������:
    char* result = (char*)malloc(64); // ���������� ���� void* � char*
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
            int digit = abs(num % base); // ���������� abs() ��� ������������� �����
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
    // �������������� ������
    char* temp = (char*)malloc(i + 1);
    for (int j = 0; j < i; j++) {
        temp[j] = result[i - j - 1];
    }
    temp[i] = '\0';
    free(result);
    return temp;
}