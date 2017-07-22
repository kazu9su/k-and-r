#include <ctype.h>
#include <stdio.h>
#include "ch5-getint.h"

#define SIZE 100

int main()
{
    int n, i;
    int array[SIZE] = {0};

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    for (i = 0; i < n; i++) {
        printf("Item %d: %d\n", i, array[i]);
    }
}

