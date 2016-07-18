#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

void itoa(int n, char s[]);
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

    {
        int n = INT_MIN;
        char s[MAXLINE];
        itoa(n, s);

        printf("%s\n", s);
        assert(strcmp("-2147483648", s) == 0);
    }

    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;

    i = 0;
    sign = n;

    do {
        s[i++] = abs(n % 10) + '0';
    } while((n /= 10) != 0);

   if (sign < 0) {
        s[i++] = '-';
        s[i] = '\0';
    }

    reverse(s);
}

int abs(int n) {
    if(n < 0) {
        printf("%d\n", n);
        return -n;
    } else
        return n;
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
