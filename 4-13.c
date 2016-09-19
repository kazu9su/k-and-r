#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

void reverse(char s[], int i);

int main()
{
    {
        char s[100] = "00001";
        reverse(s, 0);

        printf("%s\n", s);
        assert(strcmp("10000", s) == 0);
    }

    return 0;
}

void reverse(char s[], int i)
{
    int c;

    c = s[i];

    if (c != '\0') {
        reverse(s, i + 1);
    }

    s[strlen(s) - 1 - i] = c;
}
