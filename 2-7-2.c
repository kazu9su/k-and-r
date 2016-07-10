#include <stdio.h>
#include <assert.h>

unsigned int invert(unsigned int x, int p, int n);

int main()
{
    unsigned int x = 0b1111010;
    unsigned int val = invert(x, 3, 3);

    printf("%u\n", val);
    assert(val == 0b1110100);

    return 0;
}

unsigned int invert(unsigned int x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}
