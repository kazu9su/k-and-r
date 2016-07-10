#include <stdio.h>
#include <assert.h>

int lower(int c);

int main()
{
    int result1 = lower('Q');
    int result2 = lower('Z');
    int result3 = lower('D');

    assert(result1 == 'q');
    assert(result2 == 'z');
    assert(result3 == 'd');

    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
