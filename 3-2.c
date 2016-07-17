#include <stdio.h>
#include <assert.h>

void escape(char s[], char t[]);

int main ()
{
    char s[100] = "a\tb\nc\0";
    char t[100];

    escape(s, t);

    printf("%s\n", expected);

    return 0;
}

void escape(char s[], char t[])
{
    int i, k, c;
    i = k = 0;
    while ((c = s[i]) != EOF) {
        switch (c) {
        case '\n' :
            t[k] = '\\';
            t[++k] = 'n';
            break;
        case '\t' :
            t[k] = '\\';
            t[++k] = 't';
            break;
        default :
            t[k] = c;
            break;
        }
        i++;
        k++;
    }
}
