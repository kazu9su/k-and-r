#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 10

double stack[STACK_MAX];
int stack_top = 0;

void stack_push(double val) {
    if(stack_top == STACK_MAX) {
        printf("エラー:スタックが満杯です(Stack overflow)\n");
        exit(EXIT_FAILURE);
    } else {
        stack[stack_top] = val;
        stack_top++;
    }
}

double stack_pop(void)
{
    if(stack_top == 0) {
        printf("エラー:スタックが空なのにpopが呼ばれました(Stack underflow)\n");
        exit(EXIT_FAILURE);
        return 0;
    } else {
        stack_top--;
        return stack[stack_top];
    }
}

int main(void) {
    char buffer[256];
    double cal1, cal2;
    int i;

    do {
        printf("現在のスタック(%d個):", stack_top);
        for(i = 0; i < stack_top; i++) {
            printf("%0.3f", stack[i]);
        }
        printf("\n>");
        gets(buffer);
        switch(buffer[0]) {
        case '+':
            cal1 = stack_pop();
            cal2 = stack_pop();
            stack_push(cal2 + cal1);
            break;
        case '-':
            cal1 = stack_pop();
            cal2 = stack_pop();
            stack_push(cal2 - cal1);
            break;
        case '*':
            cal1 = stack_pop();
            cal2 = stack_pop();
            stack_push(cal2 * cal1);
            break;
        case '/':
            cal1 = stack_pop();
            cal2 = stack_pop();
            stack_push(cal2 / cal1);
            break;
        case '=':
            break;
        default:
            stack_push(atoi(buffer));
            break;
        }
    } while(buffer[0] != '=');

    printf("計算結果は%f です。\n", stack_pop());
    if(stack_top != 0) {
        printf("エラー:スタックにまだ数が残っています\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
