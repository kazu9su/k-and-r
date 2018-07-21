#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND (-1)
#define N (10)

int organization_search(int x, int *a, int num) {
    int n = 0, t;

    while(n < num && a[n] != x) {
        n++;
    }

    if(n < num) {
        if(n > 0) { /* 1つ前と入れ替える */
            t = a[n - 1];
            a[n - 1] = a[n];
            a[n] = t;
            return n - 1;
        }
        return n;
    }

    return NOT_FOUND;
}

int main(void) {
    int i, r, array[N];

    srand((unsigned int)time(NULL));

    /* 適当な配列を作る */
    for(i = 0; i < N; i++) {
        array[i] = rand() % 20;
    }

    for(;;) {
        printf("array ");
        for(i = 0; i < N; i++) {
            printf("[%d]:%d ", i, array[i]);
        }

        printf("\n何を探しますか(-1で終了):");
        scanf("%d", &i);
        if(i == -1) {
            break;
        }

        r = organization_search(i, array, N);

        if(r == NOT_FOUND) {
            printf("%dは見つかりません\n", i);
        } else {
            printf("%dは%d番目です\n", i, r);
        }
    }

    return EXIT_SUCCESS;
}
