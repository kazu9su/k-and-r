#include <stdio.h>

void strcat1(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}

void strcat2(char* s, char* t)
{
    while (*s)
        s++;

    while (*s++ = *t++)
        ;

    *s = '\0';
}

int main()
{
    char s[10] = "Hello ";
    char t[10] = "World!";

    strcat1(s, t);
    printf("%s\n", s);

    char s2[100] = "Hello ";
    char *t2 = "World!";

    strcat2(s2, t2);
    printf("%s\n", s2);
}
