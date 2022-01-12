#include "string_encryption.h"

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* encryption(char* s) {
    char* str_enp = malloc(100 * sizeof(char));
    int i = 0;
    int length = 0;
    int row;
    int column;

    while (s[i] != '\0')
    {
        // Calculate the string length
        i++;
    }

    length = i;
    row = sqrt(length);
    column = row + 1;
    i = 0;
    while (i < row*column && i < length)
    {
        // Copying the encrypted string
        // Row+1 is reserved for space
        str_enp[i%column*(row+1) + i/column] = s[i];

        // Add space to reserved
        if (i % row == 0)
        {
            str_enp[i*(row+1)] = ' ';
        }
        else if (i == length)
        {
            str_enp[i] = '\0';
        }

        i++;
    }

    return str_enp;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
