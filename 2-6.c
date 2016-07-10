#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    int x = 0b001110;
    int y = 0b0000000;

    printf("%d\n", setbits(x, 3, 3, y));
    // answer 0b0000111 -> 7;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    y = (y & ~(~0 << n))  + (x >> (p - (n - 1)) & ~(~0 << n));

    return y;
}
