#include <stdio.h>
#include <assert.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main()
{
    char s1[100] = "a-e\0";
    char s2[100];
    expand(s1, s2);
    printf("%s\n", s2);

    char s3[100] = "a-c-f\0";
    char s4[100];
    expand(s3, s4);
    printf("%s\n", s4);

    char s5[100] = "a-c0-9\0";
    char s6[100];
    expand(s5, s6);
    printf("%s\n", s6);

    char s7[100] = "-a-c\0";
    char s8[100];
    expand(s7, s8);
    printf("%s\n", s8);

    char s9[100] = "-a-c-\0";
    char s10[100];
    expand(s9, s10);
    printf("%s\n", s10);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k;

    for (i = j = 0; i < strlen(s1); i++) {
        if (s1[i] == '-' && i != 0 && i != (strlen(s1) - 1)) {
            for (k = s1[i - 1] + 1; k <  s1[i + 1]; k++) {
                s2[j] = k;
                j++;
            }
        } else {
            s2[j] = s1[i];
            printf("%d\n", j);
            j++;
        }
    }
}
