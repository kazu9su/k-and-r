#include <stdio.h>

int main()
{
    int i;
    int c;
    int lim = 1000;
    char s[lim];

    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; i++)
        s[i] = c;

    //for (i = 0; (i < lim -1) == ((c = getchar()) != '\n') == (c != EOF); i++)
        //s[i] = c;

    printf("%s\n", s);
}
