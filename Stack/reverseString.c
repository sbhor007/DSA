#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(char str)
{
    if (top == MAX - 1)
        printf("\nStack is overflow....!");
    else
        stack[++top] = str;
}
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int main()
{
    char str[MAX];
    printf("Enter a string : ");
    gets(str);
    for (int i = 0; i < strlen(str); i++)
        push(str[i]);
    while (top != -1)
    {
        printf("%c", pop());
    }
    return 0;
}