#include <stdio.h>
#include <string.h>

int strend(char s[], char t[])
{
    int i, j = 0;
    while (s[i])
        i++;
    while (t[j])
        j++;

    if (i < j)
        return 0;

    while (j >= 0) {
        if (s[i--] != t[j--])
            return 0;
    }

    return 1;
}

int strend2(char *s, char *t)
{
    int slen, tlen, i;

    slen = strlen(s);
    tlen = strlen(t);

    if (slen < tlen)
        return 0;

    for (i = 0; i <= tlen; i++) {
        if (*(s + slen - i) != *(t + tlen - i))
            return 0;
    }

    return 1;
}

int main()
{
    char s[100] = "hogefuga";
    char *t = "fuga";

    printf("%d\n", strend(s, t));
    printf("%d\n", strend2(s, t));
}
