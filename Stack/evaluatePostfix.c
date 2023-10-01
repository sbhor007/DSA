
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 50
int stack[MAX];
int top = -1;

void push(int no)
{
    if (top == MAX - 1)
        printf("\nstack is overflow....!");
    else
        stack[++top] = no;
}
int pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int chekOperator(char exp)
{
    if (exp == '+' || exp == '-' || exp == '*' || exp == '/' || exp == '^')
        return 1;
    else
        return 0;
}

int evaluation(char *exp)
{

    int op1, op2, result;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            int num = exp[i] - '0';
            push(num);
        }
        else if (chekOperator(exp[i]))
        {
            op1 = pop();
            op2 = pop();
            switch (exp[i])
            {
            case '+':
                result = op2 + op1;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '*':
                result = op2 * op1;
                break;
            case '/':
                result = op2 / op1;
                break;
            case '^':
                result = pow(op2, op1);
                break;
            }
            push(result);
        }
    }
}
int main()
{
    char exp[MAX];
    printf("\nEnter the expretion : ");
    scanf("%s", exp);
    evaluation(exp);
    printf("\nResult : %d", pop());
    return 0;
}