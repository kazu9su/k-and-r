#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
int sort[N];

void InsertSort(void) {
    int i, sorted, temp, insert;

    for(sorted = 0; sorted < N - 1; sorted++) {
        insert = sort[sorted + 1];

        for(i = 0; i <= sorted; i++) {
            if(sort[i] > insert) {
                break;
            }
        }

        while(i <= sorted + 1) {
            temp = sort[i];
            sort[i] = insert;
            insert = temp;
            i++;
        }
    }
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
    InsertSort();
    printf("\nソート終了:\n");

    for(i = 0; i < N; i++) {
        printf("%d ", sort[i]);
    }

    return 0;
}
