#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
int menu()
{
    int ch;
    printf("\n--------------------------");
    printf("\n1) Push.\n2) Display. \n3) Pop.\n4) Exit.");
    printf("\n--------------------------");
    printf("\nEnter your choise : ");
    scanf("%d", &ch);
    return ch;
}
int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int no)
{
    if (!isFull())
        stack[++top] = no;
    else
        printf("\nStack is overflow.....!");
}
void display()
{
    if (!isEmpty())
    {
        printf("\nstack data are : ");
        for (int i = top; i >= 0; i--)
            printf("%5d", stack[i]);
    }
    else
        printf("\nstack is empty.......!");
}
void pop()
{
    if (!isEmpty())
    {
        printf("\npop element is : %d", stack[top]);
        top--;
    }
    else
        printf("\nstack is empty.......!");
}
int main()
{
    int no;
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nenter a value : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
