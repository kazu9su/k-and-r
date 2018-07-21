#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];
int buffer[N];

void MergeSort(int n, int x[]) {
    int i, j, k, m;
    if(n <= 1) {
        return;
    }

    for (i = 0; i < 10; i++) {
        printf("%d\n", x[i]);
    }
    printf("end\n");

    i = 0;

    m = n / 2;

    printf("%d\n", m);
    MergeSort(m, x);
    MergeSort(n - m, x + m);

    for(i = 0; i < m; i++) {
        buffer[i] = x[i];
    }
    j = m;
    i = k = 0;

    while(i < m && j < n) {
        if(buffer[i] <= x[j]) {
            x[k++] = buffer[i++];
        } else {
            x[k++] = x[j++];
        }
    }

    while(i < m) {
        x[k++] = buffer[i++];
    }
}

int main(void) {
    int i;

    srand((unsigned int)time(NULL));

    printf("ソート準備:\n");
    for(i = 0; i < N; i++) {
        sort[i] = rand();
        printf("%d ", sort[i]);
    }

    printf("\nソート開始:\n");
    MergeSort(N, sort);

    printf("\nソート終了:\n");

    for(i = 0; i < N; i++) {
        printf("%d ", sort[i]);
    }

    return 0;
}
