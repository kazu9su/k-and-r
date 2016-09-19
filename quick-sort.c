#include <stdio.h>

void qsort(int v[], int left, int right);

int main()
{
    int v[100] = {9,7,3,2,4,5};
    int left = 0;
    int right = 5;
    int i;

    qsort(v, left, right);

    for (i = 0; i <= right; i++)
        printf ("%d\n", v[i]);
}

/* qsort: v[left]...v[right]を照準にソートする */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right) /* 配列が2より少ない要素を */
        return;        /* 含むときは何もしない */
    swap(v, left, (left + right) / 2); /* 分割要素を */
    last = left; /* v[0]に移動 */
    for (i = left+1; i <= right; i++) /* 分割 */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last); /* 分割要素を回復 */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: v[i]とv[j]を交換する */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
