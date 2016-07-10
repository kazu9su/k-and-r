#include <stdio.h>

int main()
{
    int i;
    int n = 26;
    char a[100] = "abcdefghijklmnopqrstuvwxyz";
    for (i = 0; i < n; i++) {
        printf("%6d%c", a[i], (i%10 == 9 || i == n-1) ? '\n' : ' ');
    }
}
