#include <stdio.h>
#include <assert.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned y);

int main ()
{
    unsigned int x = 0b0001110;
    unsigned int y = 0b0001000;

    unsigned int val = setbits(x, 3, 3, y);

    assert(val == 0b0001111);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    return y | ((x >> (p + 1 -n)) & ~(~0 << n));
}
