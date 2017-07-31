#include <stdio.h>

/* t を s にｎ文字コピーする */
void my_strncpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) && n-- > 1)
        ;

    *s = '\0';
}

void my_strncat(char *s, char *t, int n)
{
    while (*s != '\0')
        s++;

    int i;
    for (i = 0; i < n; i++)
        *s++ = *t++;

    *s = '\0';
}

int my_strncmp(char *s, char *t, int n)
{
    int i;
    for (i = 0; i < n; i++, s++, t++) {
        if (*s != *t)
            return *s - *t;
    }

    return 0;
}

int main()
{
    char *s;
    char t[100] = "hoge";

    my_strncpy(s, t, 3);

    printf("%s\n", s);

    char s2[1] = "h";
    my_strncat(s2, "ogefuga", 3);
    printf("%s\n", s2);

    printf("%d\n", my_strncmp("hogefuga", "hogehoge", 5));

    return 0;
}
