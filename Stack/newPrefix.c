#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 200
int stack[MAX];
int top = -1;
void push(char e)
{
    if (top == MAX - 1)
        printf("stack is overflow.....!");
    else
        stack[++top] = e;
}
char pop()
{
    return stack[top--];
}

int priority(char e)
{
    if (e == '(')
        return 0;
    else if (e == '+' || e == '-')
        return 1;
    else if (e == '*' || e == '/')
        return 2;
    else if (e == '^')
        return 3;
    else
        return -1;
}

void reverse(char *str)
{
    int i = 0;
    char temp[MAX];
    int len = strlen(str);
    int j = len - 1;
    while (j >= 0)
    {
        if (str[j] == '(')
            temp[i] = ')';
        else if (str[j] == ')')
            temp[i] = '(';
        else
            temp[i] = str[j];

        j--, i++;
    }
    temp[i] = '\0';
    strcpy(str, temp);
}

void Infix_To_Postfix(char *str)
{
    char x;
    char postfix[MAX];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalnum(str[i]))
        {
            postfix[j] = str[i];
            j++;
        }
        else if (str[i] == '(')
            push(str[i]);
        else if (str[i] == ')')
        {
            while ((x = pop()) != '(')
            {
                postfix[j] = x;
                j++;
            }
        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(str[i]))
            {
                postfix[j] = pop();
                j++;
            }
            push(str[i]);
        }
    }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';

    strcpy(str, postfix);
}

void brackets(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
        i++;
    }
}

void infix_to_prifix(char *str)
{
    reverse(str);
    // printf("\nreverse : %s", str);
    // brackets(str);
    // printf("\nreverse : %s", str);
    Infix_To_Postfix(str);
    printf("\nreverse : %s", str);
    reverse(str);
    printf("\nreverse : %s", str);
}
int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX], temp[MAX], x;
    int j = 0;
    printf("\nEnter the infix : ");
    scanf("%s", infix);
    // Infix_To_Postfix(infix);

    infix_to_prifix(infix);
    // printf("\nInfix to prefix : %s", infix);
    return 0;
}

// I/P ->  ((a/b)+c)-(d+(e*f))