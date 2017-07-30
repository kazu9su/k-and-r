#include <stdio.h>

void strcpy1(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void strcpy2(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

void strcpy3(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

int main()
{
    char *s = "Hello World!";
    char *p;
    char *p2;

    strcpy1(p, s);

    printf("%s\n", p);

    strcpy2(p, s);

    printf("%s\n", p);

    strcpy3(p, s);

    printf("%s\n", p);
}
