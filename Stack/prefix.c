#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000
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

void reverse(char str[], char temp[])
{
    int i = 0;
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
}

void Infix_To_Postfix(char str[], char postfix[])
{
    char x;
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
}

int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX], temp[MAX], x, elem;
    int j = 0;
    printf("\nEnter the infix : ");
    scanf("%s", infix);

    reverse(infix, temp);
    // printf("%s", temp);
    for (int i = 0; temp[i] != '\0'; i++)
    {
        if (isalnum(temp[i]))
        {
            postfix[j] = temp[i];
            j++;
        }
        else if (temp[i] == '(')
        {
            push(temp[i]);
        }
        else if (temp[i] == ')')
        {
            while ((x = pop()) != '(')
            {
                postfix[j] = x;
                j++;
            }
        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(temp[i]))
            {
                postfix[j] = pop();
                j++;
            }
            push(temp[i]);
        }
    }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    // printf("\nInfix to prefix : %s", postfix);
    reverse(postfix, prefix);
    printf("\nInfix to prefix : %s", prefix);
    return 0;
}