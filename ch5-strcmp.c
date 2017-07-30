#include <stdio.h>

/* s<t なら <0, s==t なら 0, s>t なら >0 を返す */
int strcmp1(char *s, char *t)
{
    int i;
    for(i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int strcmp2(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
int main()
{
    char *s = "Hello a";
    char *t = "Hell";

    printf("%d\n", strcmp1(s, t));
    printf("%d\n", strcmp2(s, t));
}
