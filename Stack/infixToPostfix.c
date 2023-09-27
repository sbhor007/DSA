#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
int stack[MAX];
int top = -1;
void push(char e)
{
    if (top == MAX - 1)
        printf("\nstack overflow......!");
    else
        stack[++top] = e;
}
char pop()
{
    return stack[top--];
}
int priority(char element)
{
    if (element == '(')
        return 0;
    else if (element == '+' || element == '-')
        return 1;
    else if (element == '*' || element == '/')
        return 2;
    else if (element == '^' || element == '$')
        return 3;
    else
        return -1;
}
int main()
{
    char infix[50], x;
    printf("\nEnter the infix expretion : ");
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
                printf("%c ", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(infix[i]))
            {
                printf("%c ", pop());
            }
            push(infix[i]);
        }
    }
    while (top >= 0)
        printf("%c ", pop());

    return 0;
}