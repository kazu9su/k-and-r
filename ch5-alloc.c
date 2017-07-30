#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /* allocのための記憶場所*/
static char *allocp = allocbuf; /* 次の空き位置 */

char *alloc(int n) /* n 文字へのポインタを返す*/
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* 入りきる */
        allocp += n;
        return allocp - n; /* 古いp */
    }

    return 0;
}

void afree(char *p) /* pによって指される領域を開放する */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p
}
