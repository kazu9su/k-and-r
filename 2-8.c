#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
    int x = 0b111010;

    x = rightrot(x, 3);

    printf("%d\n", x);
}

unsigned rightrot(unsigned x, int n)
{
    int i = 0;
    int nx = 0;
    
    nx = x;
    while (nx > 0) {
        nx /= 2;
        //printf("%d\n", nx);
        i++;
    }

    //printf("%d\n", i);

    if (i < n) {
        printf("桁数が足りません\n");
        return -1;
    }

    //下n桁
    int shiftbit = x & ~(~0 << n);

    //n桁右シフト
    x = x >> n;

    //i -n 桁左シフト
    shiftbit = shiftbit << (i - n);

    return x + shiftbit;
}
