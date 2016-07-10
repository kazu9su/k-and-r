#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    int x = 0b00001110;

    x = invert(x, 3, 3);
    printf("%d\n", x);
    //answer -> 0b0000000 -> 0
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p - (n - 1)));
}
