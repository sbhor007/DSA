#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(char e)
{
    if (top == MAX - 1)
        printf("\nStack Overflow.....!");
    else
        stack[++top] = e;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

void reverse_string(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
            push(str[i]);
        else
        {
            while (top != -1)
                printf("%c", pop());
            printf(" ");
        }
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
}
int main()
{
    char str[MAX];
    printf("\nEnter the string : ");
    gets(str);
    printf("\nOriginal String : %s", str);
    printf("\nReverse String : ");
    reverse_string(str);
    return 0;
}