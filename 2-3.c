#include <stdio.h>

int htoi(char s[]);


int main()
{
    char s[100] = "0XaAF\n";
    int i;

    i = htoi(s);

    printf("%d\n", i);
}

int htoi(char s[])
{
    int i, n;

    n = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        for (i = 2; s[i] != '\n' && s[i] != EOF; i++) {
            n = n * 16;
            if (s[i] == 'a' || s[i] == 'A') {
                n += 10;
            } else if (s[i] == 'b' || s[i] == 'B') {
                n += 11;
            } else if (s[i] == 'c' || s[i] == 'C') {
                n += 12;
            } else if (s[i] == 'd' || s[i] == 'D') {
                n += 13;
            } else if (s[i] == 'e' || s[i] == 'E') {
                n += 14;
            } else if (s[i] == 'f' || s[i] == 'F') {
                n += 15;
            } else {
                n += (s[i] - '0');
            }
        }
    }

    return n;

}
