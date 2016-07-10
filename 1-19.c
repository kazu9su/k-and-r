#include <stdio.h>
#define MAXLINE 1000

int getline_mine(char s[], int lim);
void reverse(char s[], char r_s[], int len);

int main()
{
    int i, k;
    char s[MAXLINE];

    i = 0;

    while ((k = getline_mine(s, MAXLINE)) > 0) {
        if (i == 0) {
            printf("%s", s);
            i++;
        } else {
            char r_s[MAXLINE];
            reverse(s, r_s, k);
            printf("%s", r_s);
            i--;
        }
    }
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

void reverse(char s[], char r_s[], int len)
{
    int i, k;
    k = 0;
    for (i=len - 2; 0 <= i; i--) {
        r_s[i] = s[k];
        k++;
    }
    r_s[len - 1] = '\n';
    r_s[len] = '\0';
}
