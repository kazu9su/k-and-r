#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sort[N];

void BinaryInsertSort(void) {
    int i, sorted, temp, insert;
    int left, mid, right;

    for(sorted = 1; sorted < N; sorted++) {
        insert = sort[sorted];

        left = 0;
        right = sorted;
        while(left < right) {
            mid = (left + right) / 2;

            if(sort[mid] < insert) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        i = left;

        while(i <= sorted) {
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
    BinaryInsertSort();
    printf("\nソート終了:\n");

    for(i = 0; i < N; i++) {
        printf("%d ", sort[i]);
    }

    return 0;
}
