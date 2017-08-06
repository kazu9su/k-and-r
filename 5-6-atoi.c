#include <stdio.h>

int atoi(char *s);

int main()
{

    printf("%d\n", atoi("1999"));

    return 0;
}

int atoi(char *s)
{
    int i, n;

    n = 0;
    for (i = 0; *s >= '0' && *s <= '9'; s++)
        n = 10 * n + (*s - '0');
    return n;
}
