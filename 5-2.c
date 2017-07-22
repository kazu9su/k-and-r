#include <ctype.h>
#include <stdio.h>
#include "ch5-getfloat.h"

#define SIZE 100

int main()
{
    int n, i;
    float array[SIZE] = {0};

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    for (i = 0; i < n; i++) {
        printf("Item %d: %f\n", i, array[i]);
    }
}

