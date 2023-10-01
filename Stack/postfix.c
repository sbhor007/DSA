#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
int stack[50];
int top = -1;

void push(char e)
{
    if (top == MAX - 1)
        printf("\nStack is overflow....!");
    else
        stack[++top] = e;
}

char pop()
{
    return stack[top--];
}

int priority(char expretion)
{
    if (expretion == '(')
        return 0;
    else if (expretion == '+' || expretion == '-')
        return 1;
    else if (expretion == '*' || expretion == '/')
        return 2;
    else if (expretion == '^')
        return 3;
    else
        return -1;
}

int main()
{

    char infix[MAX], x;
    printf("\nEnter Infix Expretion : ");
    scanf("%s", infix);
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
            printf("%c ", infix[i]);
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c ", x);
            }
        }
        else
        {
            while (priority(infix[i]) <= priority(stack[top]))
            {
                printf("%c ", pop());
            }
            push(infix[i]);
        }
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}
