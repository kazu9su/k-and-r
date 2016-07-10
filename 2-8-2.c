#include <stdio.h>
#include <assert.h>

unsigned char bit2char(char* bit);
unsigned char rightrot(unsigned char x, int n);

int main()
{
    unsigned char result = rightrot(bit2char("01011001"), 3);

    printf("%u\n", result);
    assert(result == bit2char("00101011"));

    return 0;
}

unsigned char bit2char(char* bit)
{
    unsigned char n, i;

    n = 0;
    for (i = 0; bit[i] != 0; i++) {
        n = n * 2 + (bit[i] == '1' ? 1 : 0);
    }
    
    return n;
}

unsigned char rightrot(unsigned char x, int n)
{
    unsigned char mask = ~0;
    unsigned char rightbit_on = 01;
    unsigned char leftbit_on = ~(mask >> 1);
    int i;

    for (i = 0; i < n; i++) {
        if ((x | rightbit_on) == x) {
            x >>= 1;
            x |= leftbit_on;
        } else {
            x >>= 1;
        }
    }

    return x;
}
