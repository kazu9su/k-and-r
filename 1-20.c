# include <stdio.h>

# define TABSTOP 4
# define MAXLINE 100

int getline_mine(char s[], int lim);

int detab(char s[], int len, int tab_to_space);

void clearArray(char s[]);

int main()
{
    char s[MAXLINE];
    int clocate, c;
    clocate = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            clocate += detab(s, clocate, TABSTOP);
        } else if (c == '\n') {
            printf("%s\n", s);
            clearArray(s);
            clocate = 0;
        } else {
            s[clocate] = c;
            clocate++;
        }
    }
}

int detab(char s[], int clocate, int n)
{
    int i, j;
    i = (n - (clocate % n));

    for (j = 0; j < i; j++) {
        s[clocate + j] = ' ';
    }

    return i;
}

void clearArray(char array[])
{
    int i;
    for (i = 0; i < MAXLINE; i++) {
        array[i] = '\0';
    }
}
