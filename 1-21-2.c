#include <stdio.h>

#define MAXLINE 1000
#define TAB2SPACE 4

char line[MAXLINE];
int getline_mine();

int main()
{
    int i, t;
    int spacecount, len;

    while ((len = getline_mine()) > 0) {
        spacecount = 0;
        for (i = 0; i < len; i++) {
            if (line[i] == ' ') {
                spacecount++;
            }
            if (line[i] != ' ') {
                spacecount = 0;
            }
            if (spacecount == TAB2SPACE) {
                i -= 3;
                len -= 3;
                line[i] = '\t';

                for (t = i + 1; t < len; t++)
                    line[t] = line[t+3];

                spacecount = 0;
                line[len] = '\0';
            }
        }

        printf("%s", line);
    }

    return 0;
}

int getline_mine(void)
{
    int c, i;
    extern char line[];

    for (i=0; i < MAXLINE&& (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}
