#include <stdio.h>

int my_getline(char *s, int lim);

int main()
{
    {
        char *s;

        printf("%d\n", my_getline(s, 1000));
    }

    {
        char *s;

        itoa(1111, s);

        printf("%s\n", s);
    }

    return 0;
}

int my_getline(char *s, int lim)
{
    int c, i;

    for (i=0; 0 < lim-1 && (c=getchar()) != EOF && c!='\n'; i++)
        *s++ = c;
        if (c == '\n') {
            *s++ = c;
            ++i;
    }
    *s = '\0';

    return i;
}


