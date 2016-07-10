#include <stdio.h>

int any(char sl[], char s2[]);

int main()
{
    char sl[100] = "abcdef\0";
    char s2[100] = "ghi\0";

    printf("%d\n", any(sl, s2));
}

int any(char sl[], char s2[])
{
    int i, j;

    for (i = 0; sl[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (sl[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}
