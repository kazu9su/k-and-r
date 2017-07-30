#include <stdio.h>

int strlen2(char *s)
{
    int n;

    for(n = 0; *s != '\0'; s++)
        n++;
    return n;
}

int strlen3(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}

int main()
{
    printf("%d\n", strlen2("Hello, World!"));
    printf("%d\n", strlen3("Hello, World!"));
}

