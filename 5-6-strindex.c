#include <stdio.h>

int strindex(char *s, char *t);

int main()
{
    printf("%d\n", strindex("hogefuga", "oge"));
    return 0;
}

int strindex(char *s, char *t)
{
    char *pt_s, *pt_t;
    int i;

    i = 0;
    while (*s) {
        pt_s = s;
        pt_t = t;
        while (*s == *t) {
            s++;
            t++;
        }

        if (*t == '\0')
            return i;

        s = pt_s;
        t = pt_t;
        s++;
        i++;
    }

    return -1;
}
