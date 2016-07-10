#include <stdio.h>

void squeeze(char sl[], char s2[]);

int main()
{
    char sl[100] = "abcdefgabcd\0";
    char s2[100] = "def\0";

    squeeze(sl, s2);

    printf("%s\n", sl);
}

void squeeze(char sl[], char s2[])
{
    int i, j, k, l;

    for (i = j = 0; sl[i] != '\0'; i++) {
        l = 0;
        for (k = 0; s2[k] != '\0'; k++) {
            if (sl[i] == s2[k]) {
                l = 1;
            }
        }

        if (l == 0) {
            sl[j++] = sl[i];
        }
    }

    sl[j] = '\0';
}
