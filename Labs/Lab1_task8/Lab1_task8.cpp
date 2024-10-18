#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <direct.h>

enum ret_type_t
{
    SUCCESS,
    ERROR_WRONG_CHARACTER,
    ERROR_WRONG_PATH,
    ERROR_OPEN_FILE,
    ERROR_IDENTICAL_PATHS

};
void remove_leading_zeros(char* str) {
    int i = 0;

    // Пропускаем незначащие нули
    while (str[i] == '0') {
        i++;
    }

    // Если все символы были нулями, оставляем один ноль
    if (i == strlen(str)) {
        str[0] = '0';
        str[1] = '\0';
    }
    else {
        // Сдвигаем строку, чтобы убрать ведущие нули
        memmove(str, str + i, strlen(str) - i + 1);
    }
}

// Функция для определения минимального основания системы счисления
int find_min_base(char* number) {
    int base = 2;
    int len = strlen(number);

    for (int i = 0; i < len; i++) {
        if (isdigit(number[i])) {
            if (number[i] - '0' >= base) {
                base = number[i] - '0' + 1;
            }
        }
        else if (isalpha(number[i])) {
            if (toupper(number[i]) - 'A' + 10 >= base) {
                base = toupper(number[i]) - 'A' + 11;
            }
        }
        else {
            printf("Некорректный символ\n");
            return -1; // Некорректный символ
        }
    }
    remove_leading_zeros(number);
    return base;
}

// Функция для преобразования числа из произвольной системы счисления в десятичную
long long convert_to_decimal(const char* number, int base) {
    long long result = 0;
    int len = strlen(number);

    for (int i = 0; i < len; i++) {
        if (isdigit(number[i])) {
            result = result * base + (number[i] - '0');
        }
        else if (isalpha(number[i])) {
            result = result * base + (toupper(number[i]) - 'A' + 10);
        }
        else {
            printf("Некорректный символ в файле\n");
            return -1; // Некорректный символ
        }
    }

    return result;
}

ret_type_t compare_absolute_paths(const char* path1, const char* path2) {
    char resolved_path1[260];
    char resolved_path2[260];

    // Получаем абсолютные пути
    if (_fullpath(resolved_path1, path1, sizeof(resolved_path1)) == NULL ||
        _fullpath(resolved_path2, path2, sizeof(resolved_path2)) == NULL) {
        printf("Ошибка разрешения одного из путей.\n");
        return ERROR_WRONG_PATH; // Ошибка в разрешении пути
    }

    // Сравниваем разрешенные абсолютные пути
    if (!(strcmp(resolved_path1, resolved_path2)))
    {
        return SUCCESS;
    }
    else
    {
        printf("ОДИНАКОВЫЕ ФАЙЛЫ");
        return ERROR_IDENTICAL_PATHS;
    }
    
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RUS");
    if (argc != 3) {
        printf("Неверное количество аргументов.\n");
        return 1;
    }
    compare_absolute_paths(argv[2], argv[3]);
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Ошибка открытия входного файла.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Ошибка открытия выходного файла.\n");
        return 1;
    }

    char number[100];
    remove_leading_zeros(number);

    while (fscanf(input_file, "%s", number) != EOF) {
        int base = find_min_base(number);

        if (base == -1) {
            printf("Ошибка: Некорректный символ в числе.\n");
            continue;
        }

        if (base >= 2 && base <= 36) {
            long long decimal_value = convert_to_decimal(number, base);
            fprintf(output_file, "%s %d %lld\n", number, base, decimal_value);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
