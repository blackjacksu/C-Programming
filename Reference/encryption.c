// Question source: hackerrank - encryption
// link: https://www.hackerrank.com/challenges/encryption/problem
// 

// compile cmd
// - ubuntu: gcc -Wall -g3 encryption.c -o encryption -lm
// - mac osx: gcc -Wall -g3 encryption.c -o encryption
// 

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

char* readline();
char* encryption(char* s);

int main()
{
    FILE* fptr = fopen("encrypted.txt", "w");

    char* s = readline();

    char* result = encryption(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        printf("Start input string\n");
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
    char* str_enp = (char *)malloc(100 * sizeof(char));
    char* str_nospace = (char *)malloc(100 * sizeof(char));
    int i = 0;
    int length = 0;
    int row;
    int column;
    int new_index;
    int new_align = 0;

    while (s[i] != '\0')
    {
        if (s[i] != ' ')
        {
            // Copy spaced-free string to new location 
            str_nospace[length++] = s[i];
        }
        i++;
    }

    row = sqrt(length);
    column = row;
    if (row * column < length)
    {
        column = row + 1;
    }
    
    if (row * column < length)
    {
        row = column;
    }

    i = 0;

    while (i < (row + 1) * column)
    {
        new_align = max(0, i % column - (length - 1) % column - 1);

        new_index = i % column * (row + 1) + i / column - new_align;

        if (i < length)
        {
            str_enp[new_index] = str_nospace[i];
        }
        else if (i < (length + column))
        {
            // Any index larger than (length + column) shouldn't have value
            if (i % column == (column - 1))
            {
                // The last column of the encrypted string that needs to be the terminator
                str_enp[new_index] = '\0';
            }
            else
            {
                // Add empty space
                str_enp[new_index] = ' ';
            }
        }
        else
        {
            // i >= (length + column)
        }

        i++;
    }

    return str_enp;
}