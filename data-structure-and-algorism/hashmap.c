#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *english;
    char *japanese;
} WORDSET;

typedef struct {
    WORDSET **data;
    unsigned int size;
} HASHTABLE;

unsigned int MakeHash2(char* str, unsigned int hashmax)
{
    unsigned int n, length, hash, weight;

    length = strlen(str);
    for(n = weight = hash = 0; n < length; n++, weight++) {
        /* 重率が256^7まで到達したら、一巡して再びもとに戻す */
        if(weight > 7) {
            weight = 0;
        }
        hash += (int)str[n] << (4 * weight); /* 1bit左にずらす毎に2の累乗倍になる */
    }

    return hash % hashmax;
}

unsigned int ReHash(HASHTABLE *hashtable, unsigned int firsthash)
{
    unsigned int hashval, k;
    /* firstvalからk^2だけ後ろにある空き位置を探す
     * 「k>ハッシュ表サイズの半分」となったら、それ以降は検索の無駄 */
    for(k = 1; k <= hashtable->size / 2; k++) {
        hashval = (firsthash + k * k) % hashtable->size;
        if(hashtable->data[hashval] == NULL) {
            return hashval;
        }
    }

    return -1;
}

void AddDataToMap(HASHTABLE *hashtable, WORDSET *newdata) {
    unsigned int hashval;

    /* 英単語を元にハッシュ値を作成 */
    hashval = MakeHash2(newdata->english, hashtable->size);

    /* もしもhashの位置がすでに埋まっていたら、再ハッシュを行う */
    if(hashtable->data[hashval] != NULL) {
        hashval = ReHash(hashtable, hashval);

        /* 再ハッシュ結果が-1であれば、空き位置が見つからなかった */
        if(hashval == -1) {
            printf("%sをマップに挿入しようと試みましたが、空き位置がありませんでした\n", newdata->english);
            return;
        }
    }

    /* hashvalの位置にnewdataへのポインタを格納 */
    hashtable->data[hashval] = newdata;
}

/* 英単語keyに対応する和訳をhashtableから探し出して返す */
char *GetDataFromMap(HASHTABLE *hashtable, char *key) {
    unsigned int hashval, k;
    WORDSET *word;

    /* 探索を開始するハッシュ値を求める */
    hashval = MakeHash2(key, hashtable->size);

    /* その位置から順番に、keyと同じ値を持つデータが現れるまで探索を行う */
    for(k = 0; k <= hashtable->size / 2; k++) {
        word = hashtable->data[(hashval + k * k) % hashtable->size];
        if(word != NULL) {
            if(strcmp(key, word->english) == 0) {
                return word->japanese;
            }
        }
    }

    /* ハッシュ表サイズの半分に相当する回数探し続けても見つからない場合は、該当するデータがハッシュ表の中にないことを意味する */
    return NULL;
}

/* 英単語keyに関するデータをhashtableから取り除く(データそのものは削除しない) */
WORDSET *DeleteDataFromMap(HASHTABLE *hashtable, char *key) {
    unsigned int hashval, k;
    WORDSET *word;

    /* 探索を開始するハッシュ値を求める */
    hashval = MakeHash2(key, hashtable->size);

    /* その位置から順番に、keyと同じ値を持つデータが現れるまで探索を行う */
    for(k = 0; k < hashtable->size / 2; k++) {
        word = hashtable->data[(hashval + k * k) % hashtable->size];
        if(word != NULL) {
            if(strcmp(key, word->english) == 0) {
                hashtable->data[(hashval + k * k) % hashtable->size] = NULL;

                return word;
            }
        }
    }

    return NULL;
}

void InitHashTable(HASHTABLE *hashtable, unsigned int size) {
    hashtable->data = (WORDSET**)malloc(sizeof(WORDSET*) * size);
    memset(hashtable->data, NULL, sizeof(WORDSET*) * size);
    hashtable->size = size;
}

void CleanupHashTable(HASHTABLE *hashtable) {
    free(hashtable->data);
    hashtable->size;
}

void PrintAllData(HASHTABLE *hashtable) {
    unsigned int n;
    for(n = 0; n < hashtable->size; n++) {
        if(hashtable->data[n] != NULL) {
            printf("%d:\t%s\t%s\n", n, hashtable->data[n]->english, hashtable->data[n]->japanese);
        }
    }
}

int main(void) {
    unsigned int n;
    char key[64], *japanese;
    HASHTABLE hashtable;
    WORDSET *wordfound;
    WORDSET words[5] = {
        {"dolphine", "イルカ"},{"beluga", "シロイルカ"},
        {"grampus", "シャチ"},{"medusa", "海月"},{"otter", "カワウソ"}
    };

    InitHashTable(&hashtable, 503);

    for(n = 0; n < 5; n++) {
        AddDataToMap(&hashtable, &words[n]);
    }

    do {
        printf("どの操作を行いますか？(1:検索 2:削除 3:全表示 0:終了)\n>" );
        scanf("%d", &n);
        switch(n) {
            case 1:
                printf("検索する英単語を入力してください:");
                scanf("%s", key);
                japanese = GetDataFromMap(&hashtable, key);
                if(japanese != NULL) {
                    printf("%sの和訳は%sです\n", key, japanese);
                } else {
                    printf("%sがマップの中に見つかりませんでした\n", key);
                }
                break;
            case 2:
                printf("削除する英単語を入力してください:");
                scanf("%s", key);
                wordfound = DeleteDataFromMap(&hashtable, key);
                if(wordfound != NULL) {
                    printf("%sをマップから削除しました\n", key);
                } else {
                    printf("%sがマップの中に見つかりませんでした\n", key);
                }
                break;
            case 3:
                PrintAllData(&hashtable);
                break;
        }
    } while(n != 0);

    CleanupHashTable(&hashtable);

    return 0;
}
