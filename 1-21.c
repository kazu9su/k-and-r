# include <stdio.h>

# define TABSTOP 4
# define MAXLINE 100

int entab(char s[], int len, int blank_n, int tab_to_space);

void clearArray(char s[]);

int main()
{
    char s[MAXLINE];
    int blank_n, clocate, c;
    blank_n = 0;
    clocate = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blank_n++;
        } else if (c == '\n') {
            printf("%s\n", s);
            clearArray(s);
            clocate = 0;
        } else {
            if (blank_n > 0) {
                clocate += entab(s, clocate, blank_n, TABSTOP);
                blank_n = 0;
            }
            s[clocate] = c;
            clocate++;
        }
    }
}

int entab(char s[], int clocate, int blank_n, int n)
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
