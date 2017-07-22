#ifndef CH5_BUFFER_H
#define CH5_BUFFER_H

#include <stdio.h>

#define BUFFER_SIZE 10

char buf[BUFFER_SIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp > BUFFER_SIZE) {
        printf("ungetch: buffer is full\n");
    }
    else {
        buf[bufp++] = c;
    }
}
#endif
