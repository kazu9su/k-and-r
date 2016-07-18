#include <stdio.h>
#include <assert.h>

#define MAXLINE 1000

int strrindex(char s[], char t[]);

int main()
{
    {
        char s[MAXLINE] = "hogefugahoge\0";
        char t[MAXLINE] = "hoge\0";

        int found = strrindex(s, t);
        printf("%d\n", found);
        assert(8 == found);
    }

    {
        char s[MAXLINE] = "Hello Hello Hello\0";
        char t[MAXLINE] = "Hello\0";

        int found = strrindex(s, t);
        printf("%d\n", found);
        assert(12 == found);
    }

    return 0;
}

int strrindex(char s[], char t[])
{
    int i, j, k, found;

    found = -1;
    for (i=0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) {}

        if (k > 0 && t[k] == '\0')
            found = i;
    }

    return found;
}
