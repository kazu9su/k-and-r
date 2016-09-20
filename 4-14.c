#include <stdio.h>
#include <assert.h>

#define swap(t,x,y) {t c = y; y = x; x = c;}

int main()
{
    {
        int x = 1;
        int y = 2;
        swap(int, x, y);

        printf("x is %d\n", x);
        assert(x == 2);
        printf("y is %d\n", y);
        assert(y == 1);
    }

    return 0;
}
