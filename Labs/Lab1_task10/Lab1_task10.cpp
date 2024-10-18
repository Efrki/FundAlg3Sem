#include "Header.h"



int main() {
    setlocale(LC_ALL, "RUS");
    int base;
    printf("Введите основание системы счисления (от 2 до 36): ");
    if (scanf("%d", &base) != 1 || base < 2 || base > 36) {
        printf("Ошибка: Некорректное основание.\n");
        return 1;
    }

    long long max_abs_value = LLONG_MIN; // Инициализируем минимальным значением
    char* max_abs_string = NULL;
    char str[100];

    printf("Введите числа в системе счисления с основанием %d (окончание ввода: \"Stop\"):\n", base);
    while (1) {
        if (scanf("%s", str) != 1) {
            printf("Ошибка: Некорректный ввод.\n");
            return 1;
        }
        if (strcmp(str, "Stop") == 0) {
            break;
        }
        long long value = convert_string_to_int(str, base);
        if (value == LLONG_MIN) { // Проверяем на ошибку преобразования
            return 1;
        }
        if (abs(value) > abs(max_abs_value)) { // Используем abs() для сравнения модулей
            max_abs_value = value;
            if (max_abs_string != NULL) {
                free(max_abs_string);
            }
            max_abs_string = strdup(str);
        }
    }

    printf("Максимальное по модулю число: %lld\n", max_abs_value);
    printf("Его строковое представление в различных системах счисления:\n");
    printf("  Десятичная: %lld\n", max_abs_value);
    printf("  Девятичная: %s\n", convert_int_to_string(max_abs_value, 9));
    printf("  Восемнадцатичная: %s\n", convert_int_to_string(max_abs_value, 18));
    printf("  Двадцатисемичная: %s\n", convert_int_to_string(max_abs_value, 27));
    printf("  Тридцатишестичная: %s\n", convert_int_to_string(max_abs_value, 36));

    free(max_abs_string);
    return 0;
}

