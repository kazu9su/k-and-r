#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND (-1)
#define N (10)

int search(int x, int *a, int num) {
    int n = 0, t;
    /* 最後の値をxに入れ替える(番兵) */
    t = a[num - 1];
    a[num - 1] = x;

    while(a[n] != x) {
        n++;
    }

    a[num - 1] = t;
    if(n < num - 1) {
        return n; /* 最後以外が一致 */
    }

    if(x == t) { /* 一番最後が一致 */
        return n;
    }

    return NOT_FOUND;
}

int main(void) {
    int i, r, array[N];

    srand((unsigned int)time(NULL));

    printf("array ");
    for(i = 0; i < N; i++) {
        printf("[%d]:%d ", i, array[i] = rand() % 20);
    }

    printf("\n何を探しますか:");
    scanf("%d", &i);

    r = linear_search(i, array, N);

    if(r == NOT_FOUND) {
        printf("%dは見つかりません\n", i);
    } else {
        printf("%dは%d番目です\n", i, r);
    }

    return 0;
}
