#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(char str)
{
    if (top == MAX - 1)
        printf("\nStack is overflow...!");
    else
        stack[++top] = str;
}
void pop()
{
    stack[top--];
}
int checkPalindrome(char *str)
{
    int front = 0; // for track first character of a string
    for (int i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        if (stack[top] == stack[front])
        {
            pop();
            front++;
        }
        else
            return 0;
    }
    if (strlen(str) / 2 == top)
        return 1;
    else
        return 0;
}
int main()
{
    char str[MAX];
    printf("Enter a string : ");
    scanf("%s", str);
    if (checkPalindrome(str))
        printf("\n%s is plindrom", str);
    else
        printf("\n%s is not plindrom", str);
    return 0;
}