#include <stdio.h>
#include <string.h>

void itoa(int n, char *s);
void reverse(char *s);

int main()
{
    {
        char s[10] = "hogehoge";
        reverse(s);
        printf("%s\n", s);
    }

    {
        char s[10];

        itoa(-1000, s);
        printf("%s\n", s);
    }

    return 0;
}

void itoa(int n, char *s)
{
    int i, sign;
    char *pt;

    pt = s;
    if ((sign = n) < 0)
        n = -n;
    i = 0;

    do {
        *s++ = n % 10 + '0';
    } while ((n /=  10) > 0);

    if (sign < 0)
        *s++ = '-';

    *s = '\0';
    s = pt;
    reverse(s);
}

void reverse(char *s)
{
    char *p;
    char tmp;

    p = s;

    while(*s)
        s++;
    s--;

    while (p < s) {
        tmp = *s;
        *s = *p;
        *p = tmp;
        s--;
        p++;
    }
}
