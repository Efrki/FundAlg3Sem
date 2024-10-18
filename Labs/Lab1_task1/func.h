#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int is_digit(char* argv) {
    for (int i = 0; i < strlen(argv); i++)
    {
        if (isalpha(argv[i]))
        {

            return 0;
        }
    }
    return 1;
}

enum ret_type_t {
    SUCCSESS,
    ERROR
};
typedef ret_type_t(*callback)(char*);

ret_type_t funcForH(char* argv) {
    //Пишет все натур числа до 100 которые делятся на входное число
    int argvInt = atoi(argv);

    if (argvInt <= 0 || argvInt > 100)
    {
        printf("Your number doesn't fit the conditions");
        return ERROR;
    }
    else {
        for (short i = argvInt; i <= 100; i += argvInt)
        {
            printf("%d ", i);
        }
    }

    return SUCCSESS;
}

ret_type_t funcForP(char* argv) {
    //Проверяет число на простоту
    int argvInt = atoi(argv);
    if (argvInt == 0 || argvInt == 1)
    {
        printf("This number isn't composite or prime");
        return ERROR;
    }
    if (argvInt == 2)
    {
        printf("Your number is prime");
        return SUCCSESS;
    }
    if (argvInt < 0)
    {
        printf("Your number is negative");
        return ERROR;
    }
    if (argvInt > 2000000000)
    {
        printf("Overflow Error");
        return ERROR;
    }

    for (int i = 2; i < sqrt(argvInt) + 1; ++i)
    {
        if (argvInt % i == 0)
        {
            printf("The number is composite");
            return SUCCSESS;
        }
    }

    printf("The number is prime");
    return SUCCSESS;
}


ret_type_t funcForS(char* argv) {
    //Выводит цифры числа х в шестнадцатеричной системе счисления
    int argvInt = atoi(argv);
    char hex[20];
    snprintf(hex, sizeof(hex), "%X", argvInt);
    for (int i = 0; i < (int)strlen(hex); i++) {
        printf("%c ", hex[i]);
    }
    printf("\n");
    return SUCCSESS;
}

ret_type_t funcForA(char* argv) {
    //Сумма чисел от 1 до argv
    int argvInt = atoi(argv);

    if (argvInt < 0)
    {
        printf("This number doenst fit the coniditions");
        return ERROR;
    }
    if (argvInt > 20000000)
    {
        printf("Overflow Error");
        return ERROR;
    }
    int sum = ((1 + argvInt) * argvInt) / 2;
    printf("%d", sum);

    return SUCCSESS;
}
ret_type_t funcForF(char* argv) {
    //Факториал argv
    int argvInt = atoi(argv);
    if (argvInt > 20)
    {
        printf("Overflow Error");
        return ERROR;
    }
    if (argvInt < 0)
    {
        printf("This number doenst fit the coniditions");
        return ERROR;
    }

    int answ = 1;
    for (int i = 1; i <= argvInt; i++)
    {
        answ = answ * i;
    }
    printf("Factorial: %d", answ);

    return SUCCSESS;
}

ret_type_t funcForE(char* argv) {
    //Выводит таблицу степеней
    int argvInt = atoi(argv);
    if (argvInt < 0 || argvInt > 10)
    {
        printf("This number doenst fit the coniditions");
        return ERROR;

    }
    for (int i = 1; i < 10; ++i)
    {
        printf("\n");
        for (int j = 1; j <= argvInt; ++j)
        {
            printf("%15llu", (long long)pow(i, j));
        }
    }

    return SUCCSESS;
}


int findFlag(char* qarg, const char** flags, int size) {
    for (int i = 0; i < size; ++i)
    {
        if (!(strcmp(qarg, flags[i])))
        {
            return i;
        }

    }

    printf("This flag doesn't exist");
    return -1;
}