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