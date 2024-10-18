#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

enum ret_type_t {
    SUCCESS,    //�����
    ERROR_NAN,   //�� �������� ������
    ERROR_FULL,  //������������
    ERROR_ARGS,  //���������� ���������� ��������
    ERROR_EPS   //������� ������� �������� �������
};
typedef double (*callback)(double);

//������� �� ���������� ������������� � double-����
double chToD(char* x) {
    double xD = 0;
    double m = 10;
    double mBuf = m;
    int flag = 1;


    for (int i = 0; i < (int)strlen(x); ++i) {
        if (x[i] == '.') {
            flag = 0;
            m = 10.0;
            mBuf = m;
            continue;
        }
        if (flag) {
            xD = xD * m + (x[i] - '0');
        }
        else {
            xD = xD + ((double)(x[i] - '0')) / m;
            m *= 10.0;
            if (mBuf > m) {
                return ERROR_FULL;
            }
            mBuf = m;
        }
    }
    return xD;
}

//������� ��� ������� ���������
double funcA(double x) {
    return log(1.0 + x) / x;
}

//������� ��� ������� ���������
double funcB(double x) {
    return powf(exp(1), -(powf(x, 2.0) / 2.0));
}

//������� ��� �������� ���������
double funcC(double x) {
    return log(1 / (1 - x));
}

//������� ��� ���������� ���������
double funcD(double x) {
    return powf(x, x);
}

//������� ��� �������� ��������� �� 0 �� 1
int integral(double eps, callback func) {
    double res = 0.0;
    double start = eps;
    while (1.0 - start >= eps) {
        res += ((func(start) + func(start + eps)) / 2.0) * eps;
        start += eps;
    }
    printf("The result is: %f\n", res);
    return SUCCESS;
}


//��������� �������� �� ��������� ������������� ������������ ������
int checkNumber(char* x) {
    int flagDot = 0, flagMin = 0;
    for (int i = 0; i < (int)strlen(x); i++) {
        if ((x[i] < '0' || x[i] > '9') && (x[i] != '.') && (x[i] != '-')) {
            return ERROR_NAN;
        }
        if (x[i] == '.') {
            flagDot++;
            if (flagDot > 1) {
                return ERROR_NAN;
            }
        }
        if (x[i] == '-') {
            flagMin++;
            if (flagMin > 1) {
                return ERROR_NAN;
            }
        }
    }
    return SUCCESS;
}
