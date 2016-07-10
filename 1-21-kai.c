#include <stdio.h>
#define MAXCHAR 100
#define TABSTOP 4

void entab();

int main()
{
    int c;
    char str[MAXCHAR];
    int i, j;
    i = 0;
    while((c = getchar()) != EOF) {
        str[i++] = c;
        if (c == '\n') {
            entab(str);
            for (j = 0; str[j] != '\n'; j++) {
                printf("%c", str[j]);
            }
            printf("\n");
            i = 0;
        }
    }
}

void entab(char str[])
{
    int i;
    int tno = 0;
    int sno = 0;
    int j = 0;

    for (i = 0; str[i] != '\n'; i++) {
        if (str[i] == '\t') {
            tno++;
        } else if (str[i] == ' ') {
            sno++;
        } else {
            
        }
    }

    tno += sno / TABSTOP;
    sno += sno % TABSTOP;

    for (; j < tno && j < MAXCHAR; j++) {
        str[j] = '\t';
    }

    for (; j < sno && j < MAXCHAR; j++) {
        str[j] = ' ';
    }

    str[j++] = '\n';
    for (; j < MAXCHAR; j++) {
        str[j] = '\0';
    }
    
    return;
}
