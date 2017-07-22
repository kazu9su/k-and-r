#ifndef CH5_GETINT_H
#define CH5_GETINT_H

#include <ctype.h>
#include <stdio.h>
#include "ch5-buffer.h"

/* getint: 入力から次の整数を取り出して *pn に入れる */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* 空白を飛ばす */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* 数字ではない */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    if (!isdigit(c) && c != EOF) {
        ungetch(c);
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#endif
