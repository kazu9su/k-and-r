#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct {
    char *title;
    char *author;
    int bookID;
    int available;
} book;

book *bookarray[N];

void initdata(void) {
    int n;
    for(n = 0; n < N; n++) {
        bookarray[n] = (book*)malloc(sizeof(book));
    }

    bookarray[0]->title = "book0";
    bookarray[1]->title = "book1";
    bookarray[2]->title = "book2";
    bookarray[3]->title = "book3";
    bookarray[4]->title = "book4";
    bookarray[0]->author = "author0";
    bookarray[1]->author = "author1";
    bookarray[2]->author = "author2";
    bookarray[3]->author = "author3";
    bookarray[4]->author = "author4";
    bookarray[0]->bookID = 1000;
    bookarray[1]->bookID = 502;
    bookarray[2]->bookID = 731;
    bookarray[3]->bookID = 628;
    bookarray[4]->bookID = 1;
    bookarray[0]->available = 1;
    bookarray[1]->available = 0;
    bookarray[2]->available = 0;
    bookarray[3]->available = 1;
    bookarray[4]->available = 1;
}

void cleanupdata(void) {
    int n;
    for(n = 0; n < N; n++) {
        free(bookarray[n]);
    }
}

void sortbook(int bottom, int top) {
    int lower, upper, div;
    book *temp;

    if(bottom >= top) {
        return;
    }

    div = bookarray[bottom]->bookID;
    for(lower = bottom, upper = top; lower < upper;) {
        while(/*lower < upper && */bookarray[lower]->bookID < div) {
            lower++;
        }
        while(/*lower < upper && */bookarray[upper]->bookID > div) {
            upper--;
        }
        if(lower<upper) {
            /* データ(へのポインタ)の順番を入れ替える */
            temp = bookarray[lower];
            bookarray[lower] = bookarray[upper];
            bookarray[upper] = temp;
            lower++;
            upper--;
        }
    }
    sortbook(bottom, upper);
    sortbook(upper + 1, top);
}

/* bookのなかからbookIDがkeyと一致するデータをバイナリサートで検索して、その添字を返す。見つからなければ-1を返す */
int searchbook(book *books[], int size, int key) {
    int left, mid, right;

    left = 0;
    right = size;
    while(left < right) {
        mid = (left + right) / 2;
        if(books[mid]->bookID < key) { /* bookIDの大小を比較 */
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if(books[left]->bookID == key) {
        return left;
    }

    return -1;
}

int main(void) {
    int key, position;

    initdata();
    sortbook(0, N - 1); /* 最初に管理番号順にソートしておく */

    /* 検索キーとして本の管理番号を入力 */
    while(1) {
        printf("検索する本の番号を入力してください"
                "(0で終了):");
        scanf("%d", &key);
        if(key == 0) {
            break;
        }

        /* 検索して結果を表示 */
        position = searchbook(bookarray, N - 1, key);
        if(position != -1) {
            printf("--次の本が見つかりました--\n"
                    "[タイトル]%s \n[著者]%s \n[管理番号]%d \n",
                    bookarray[position]->title,
                    bookarray[position]->author,
                    bookarray[position]->bookID);
            if(bookarray[position]->available != 0) {
                puts("この本は貸出可能です\n");
            } else {
                puts("この本は貸出中です\n");
            }
        } else {
            puts("お探しの本は見つかりませんでした。\n");
        }
    }

    cleanupdata();
    return 0;
}
