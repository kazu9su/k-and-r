#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXVAL 100

int getop(char*);
void push(double);
double pop(void);
int sp = 0;
double val[MAXVAL];

int main(int argc, char *argv[])
{
    int type;
    double op2;

    while(--argc > 0) {
        switch(type = getop(*++argv)) {
            case NUMBER:
                push(atof(*argv));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("fuga");
                }
                break;
            default:
                printf("fugaga");
        }
    }

    printf("\t%.8g\n", pop());

    return 0;
}

int getop(char *s)
{
    char c;
    if (isdigit(c = s[0])) {
        return NUMBER;
    } else if (c == '-' && isdigit(s[1])) {
        return NUMBER;
    } else {
        return c;
    }
}

void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("hoge");
    }
}

double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("fuga");
        return 0.0;
    }
}
