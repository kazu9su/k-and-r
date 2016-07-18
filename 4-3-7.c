#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000
#define MAXOP 100  /* 被演算数、演算子の最大サイズ */
#define MAXVAL 100
#define NUMBER '0' /* 数字があったという記号 */
#define MAXVAR 26

void push(double f);
double pop(void);
int getop(char s[]);
int getch(void);
void ungetch(int c);
double print();
void assign_var(double v, int i);
double read_var(int i);

int sp = 0;         /* スタック・ポインタ */
double val[MAXVAL]; /* 値のスタック */
int var[MAXVAR];
double printed;

int main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(fmod(pop(), op2));
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case 's' :
                push(sin(pop()));
                break;
            case 'c' :
                push(cos(pop()));
                break;
            case 'p':
                push(print());
                break;
            case 'x':
                op2 = pop();
                op1 = pop();
                push(op2);
                push(op1);
                break;
            case 'w':
                push(type);
                break;
            case 'r':
                push(type);
                break;
            case '\n':
                printf("\t%.8g\n", printed = pop());
                assign_var(printed, 'R');
                break;
            default:
                if (type >= 'A' && type <= 'Z') {
                    op2 = pop();
                    if (op2 == 'w') {
                        if (type == 'R') {
                            printf("cannot use R for write!\n");
                        } else {
                            op1 = pop();
                            assign_var(op1, type);
                            push(op1);
                        }
                    } else if(op2 == 'r') {
                        push(read_var(type));
                    }
                } else {
                    printf("unknown command given\n");
                }
                break;
        }
    }

    return 0;
}

void assign_var(double v, int i)
{
    if ((i >= 'A') && (i <= 'Z')) {
        var[i - 'A'] = v;
    } else {
        printf("variable is out of range.\n");
    }
}

double read_var(int i)
{
    double v;

    v = var[i - 'A'];
    if (v) {
        return v;
    } else {
        printf("specified variable does not exist. %c", i);
        return 0.0;
    }
}

double print()
{
    if (sp > 0) {
        double top = val[sp - 1];
        printf("\t%.8g\n", top);
        return top;
    } else {
        printf("error : stack empty\n");
        return 0.0;
    }
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error : stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error : stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '-') {
        if (!isdigit(s[++i] = c = getch())) {
            ungetch(c);
            return '-';
        }

        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];  /* ungetch用のバッファ */
int bufp = 0;       /* buf中の次の空き位置 */

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
