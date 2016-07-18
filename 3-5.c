#include <stdio.h>
#include <string.h>
#include <assert.h>

void itob(unsigned int n, char s[], int b);
void reverse(char s[]);

#define MAXLINE 1000

int main()
{
    {
        unsigned int n = 100;
        char s[MAXLINE];
        int b = 2;
        itob(n, s, b);

        printf("%s\n", s);
        assert(strcmp("1100100", s) == 0);
    }

    {
        unsigned int n = 100;
        char s[MAXLINE];
        int b = 8;
        itob(n, s, b);

        printf("%s\n", s);
        assert(strcmp("144", s) == 0);
    }

    {
        unsigned int n = 1000;
        char s[MAXLINE];
        int b = 16;
        itob(n, s, b);

        printf("%s\n", s);
        assert(strcmp("3E8", s) == 0);
    }


    return 0;
}

void itob(unsigned int n, char s[], int b)
{
    int i, mod;
    i = 0;

    do {
        mod = n % b;
        s[i++] = (mod < 10) ? mod + '0' : mod - 10 + 'A';
    } while((n /= b) != 0);

    reverse(s);
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
