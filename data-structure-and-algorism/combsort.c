#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

void CombSort(void) {
    int i, temp, flag, gap;
    gap = N;

    do {
        gap = ( gap * 10 ) / 13;
        if(gap == 0) {
            gap = 1;
        }

        flag = 1;
        for(i = 0; i < N - gap; i++) {
            if (sort[i] > sort[i + gap]) {
                flag = 0;
                temp = sort[i];
                sort[i] = sort[i + gap];
                sort[i + gap] = temp;
            }
        }
    } while((gap > 1) || flag != 1);
}

int main(void) {
    int i;

    srand((unsigned int)time(NULL));

    printf("ソート準備:\n");
    for(i = 0; i < N; i++) {
        sort[i] = rand() % 1000;
        printf("%d ", sort[i]);
    }

    printf("\nソート開始:\n");
    CombSort();

    printf("\nソート終了:\n");

    for(i = 0; i < N; i++) {
        printf("%d ", sort[i]);
    }

    return 0;
}
