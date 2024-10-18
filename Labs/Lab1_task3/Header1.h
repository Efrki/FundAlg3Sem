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
typedef ret_type_t(*callback)(char*,char*, char*, char*);

ret_type_t funcForQ(char* argv) {
    //Пишет все натур числа до 100 которые делятся на входное число
    int argvInt = atoi(argv);

    if (argv < 0 || argvInt > 100)
    {
        printf("Your number doesn't fit the conditions");
        return ERROR;
    }
    else {
        for (short i = argvInt; i < 100; i + argvInt)
        {
            printf("%d", i);
        }
    }

    return SUCCSESS;
}

ret_type_t funcForM(char* argvFirst, char* argvSecond) {
    //Проверяет число на простоту
    int argvFInt = atoi(argvFirst);
    int argvSInt = atoi(argvSecond);

    if (argvFInt % argvSInt == 0)
    {
        printf("The first number is a multiple of the second");
        return SUCCSESS;
    }
    else
    {
        printf("The first number isn't a multiple of the second");
        return SUCCSESS;
    }
}


ret_type_t funcForT(char* argvFirst, char* argvSecond, char* argvThird, char* argvFourth) {
    //Выводит цифры числа х в шестнадцатеричной системе счисления
    double eps = atoi(argvFirst);
    double argvS = atoi(argvSecond);
    double argvT = atoi(argvThird);
    double argvF = atoi(argvFourth);

    double ST = argvS * argvS + argvT * argvT;
    double SF = argvS * argvS + argvF * argvF;
    double TF = argvT * argvT + argvF * argvF;

    if (fabs(ST - argvF * argvF) < eps || fabs(SF - argvT * argvT) < eps || fabs(TF - argvS * argvS) < eps)
    {
        printf("These sides are the sides of a right triangle.");
        return SUCCSESS;
    }
    else {
        printf("These sides aren't the sides of a right triangle.");
        return SUCCSESS;
    }
    
}


int findFlag(char* qarg, const char** flags, int size) {
    for (int i = 0; i < size; ++i)
    {
        if (!(strcmp(qarg, flags[i])))
        {
            return i;
        }

    }


    return -1;
}