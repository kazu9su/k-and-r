#include <stdio.h>
#include <assert.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
    int x = 0;
    int n = 10000;
    int v[n];
    int i;
    clock_t start, end;

    for (i=0; i < n; i++) {
        v[i] = i;
    }

    start = clock();
    printf("%lu\n", start);
    int mid = binsearch(x, v, n);
    end = clock();
    printf("%lu\n", end);
    assert(mid == 0);

    start = clock();
    printf("%lu\n", start);
    mid = binsearch2(x, v, n);
    end = clock();
    printf("%lu\n", end);
    assert(mid == 0);
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid, found;
    low = 0;
    high = n -1;
    found = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            found = mid;
            low = mid + 1;
        }
    }

    return x == v[found] ? found : -1;
}
