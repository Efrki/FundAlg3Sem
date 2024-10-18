// Lab1_task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


enum ret_type_t {
    SUCCSESS,
    ERROR
};
typedef ret_type_t(*callback)(char*);

int factorial(int x) {\
    int ans = 1;
    if (x == 0)
    {
        return 1;
    }
    for (int i = 0; i < x; ++i)
    {
        ans *= i;
    }
    return ans;
}

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

ret_type_t eLim(char* argv) {
    int argvInt = atoi(argv);
    double e = 2.0;
    double prev_e = 0.0;
    double n = 0.25;

    while (fabs(e - prev_e) > argvInt) {
        prev_e = e;
        e += n; // Используем pow() для вычисления (1 + 1/n)^n
        n = n / 2;
        
    }
    printf("%.30f", e);
    return SUCCSESS;
}


ret_type_t eRow(char* argv) {
    int argvInt = atoi(argv);
    double e = 2.0;
    double prev_e = 0.0;
    int i = 2;
    while (fabs(prev_e - e) > e)
    {
        prev_e = e;
        e += 1 / factorial(i);
        ++i;
    }
    printf("e with row: %f", e);
    return SUCCSESS;
}

ret_type_t eEquation(char* argv) {
    return SUCCSESS;
}

ret_type_t piLim(char* argv) {
    return SUCCSESS;
}

ret_type_t piRow(char* argv) {
    return SUCCSESS;
}

ret_type_t piEquation(char* argv) {
    return SUCCSESS;
}

ret_type_t lnLim(char* argv) {
    return SUCCSESS;
}

ret_type_t lnRow(char* argv) {
    return SUCCSESS;
}

ret_type_t lnEquation(char* argv) {
    return SUCCSESS;
}

ret_type_t rootLim(char* argv) {
    return SUCCSESS;
}

ret_type_t rootRow(char* argv) {
    return SUCCSESS;
}

ret_type_t rootEquation(char* argv) {
    return SUCCSESS;
}

ret_type_t yLim(char* argv) {
    return SUCCSESS;
}

ret_type_t yRow(char* argv) {
    return SUCCSESS;
}

ret_type_t yEquation(char* argv) {
    return SUCCSESS;
}

int main(int argc, char* argv[])
{
    if (!(is_digit(argv[1])))
    {
        return 1;
    }
    eLim(argv[1]); eRow(argv[1]);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
