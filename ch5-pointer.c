#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);
char *alloc(int n);

int main()
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int getline_mine(char *, int);
char *alloc(int);

/* readlines: 入力行を読み込む */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline_mine(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* 改行を消す */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

/* writelines: 出力行を書き出す */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for(i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getline_mine(char s[], int lim)
{
    int c, i;

    for (i=0; 0 < lim-1 && (c=getchar()) != EOF && c!='\n'; i++)
        s[i] =c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /* allocのための記憶場所*/
static char *allocp = allocbuf; /* 次の空き位置 */

char *alloc(int n) /* n 文字へのポインタを返す*/
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* 入りきる */
        allocp += n;
        return allocp - n; /* 古いp */
    }

    return 0;
}

