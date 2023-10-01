// evaluate prefix expretion
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int no)
{
    if (top == MAX - 1)
        printf("\nStack is overflow...!");
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
int checkOperator(char exp)
{
    if (exp == '+' || exp == '-' || exp == '*' || exp == '/' || exp == '^')
        return 1;
    else
        return 0;
}
void evaluation(char *exp)
{
    int op1, op2, result;
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            int num = exp[i] - '0';
            push(num);
        }
        else if (checkOperator(exp[i]))
        {
            op1 = pop();
            op2 = pop();
            switch (exp[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '^':
                result = pow(op1, op2);
                break;
            }
            push(result);
        }
    }
}
int main()
{
    char exp[MAX];
    printf("\nEnter the prefix expretion to evaluate : ");
    scanf("%s", exp);
    evaluation(exp);
    printf("\nResult : %d", pop());
    return 0;
}