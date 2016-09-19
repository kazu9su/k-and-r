#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

int itoa(int n, char s[]);
void reverse(char s[]);
int abs(int n);

#define MAXLINE 1000

int main()
{
    {
        int n = 10000;
        char s[MAXLINE];
        itoa(n, s);

        printf("%s\n", s);
        assert(strcmp("10000", s) == 0);
    }

    {
        int n = -10000;
        char s[MAXLINE];
        itoa(n, s);

        printf("%s\n", s);
        assert(strcmp("-10000", s) == 0);
    }

    return 0;
}

int itoa(int n, char s[])
{
    int pos = 0;

    if (n < 0) {
        s[pos++] = '-';
    }

    if (n / 10) {
        pos = itoa(n/10, s);
    }

    s[pos++] = (n < 0 ? -n : n) % 10 + '0';

    return pos;
}
