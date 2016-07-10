#include <stdio.h>
#include <assert.h>

/*
 * マイナス1された値と&すると、元の数の最も右の1ビットが消える
 * ex)
 * 24 -> 0001 1000
 * 23 -> 0001 0111
 * --------------------
 * &     0001 0000 -> 16
 * 15 -> 0000 1111
 * --------------------
 * &     0000 0000
 */
int bitcount(unsigned int x);
int bitcount2(unsigned int x);

int main()
{
    int result = bitcount(0b01100111);
    int result2 = bitcount2(0b01100111);

    printf("%d\n", result);
    printf("%d\n", result2);
    assert(result == result2);
    return 0;
}

int bitcount(unsigned int x)
{
    int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01)
            b++;
    }

    return b;
}

int bitcount2(unsigned int x)
{
    int b;

    for (b = 0; x != 0; x = x & (x-1)) {
        b++;
    }

    return b;
}
