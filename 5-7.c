#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *buf_lines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);
#define MAXLEN 1000
int getline_mine(char *, int);

int main()
{
    int nlines;
    char buf_lines[MAXLINES * MAXLEN];

    if ((nlines = readlines(lineptr, MAXLINES, buf_lines)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: 入力行を読み込む */
int readlines(char *lineptr[], int maxlines, char *buf_lines)
{
    int len, nlines, i;
    char *p, line[MAXLEN];

    nlines = i = 0;
    while ((len = getline_mine(line, MAXLEN)) > 0)
        if (nlines >= maxlines)
            return -1;
        else {
            line[len-1] = '\0'; /* 改行を消す */
            strcpy(&buf_lines[i], line);
            lineptr[nlines++] = &buf_lines[i];
            i += len;
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
