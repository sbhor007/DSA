// S14) Write a ‘C’ program to accept a string from user and reverse it using Dynamic implementation of Stack

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct dstack
{
    int data;
    struct dstack *nextAdd;
};
typedef struct dstack node;
node *top = NULL;
node *newnode, *temp;

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
void push(char str)
{
    newnode = (node *)malloc(sizeof(node));
    newnode->data = str;
    newnode->nextAdd = NULL;
    if (top == NULL)
        top = newnode;
    else
    {
        newnode->nextAdd = top;
        top = newnode;
    }
}
char pop()
{
    // char ch;
    if (isEmpty())
        printf("\nStack is empty ....!");
    else
    {
        temp = top;
        top = temp->nextAdd;
        printf("%c", temp->data);
        // ch = temp->data;
        free(temp);
    }
    // return ch;
}
int main()
{
    char str[100];
    printf("Enter a string : ");
    gets(str);
    printf("\nOriginal string : %s", str);
    printf("\nReverse string : ");
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
            push(str[i]);
        else
        {
            while (!isEmpty())
            {
                pop();
                // printf("%c", pop());
            }
            printf(" ");
        }
    }

    while (!isEmpty())
    {
        pop();
        // printf("%c", pop());
    }

    return 0;
}