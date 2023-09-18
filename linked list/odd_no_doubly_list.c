// Write a 'C' program to create doubly linke list and display nodes having odd value.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct dlink
{
    struct dlink *prevAdd, *nextAdd;
    int data;
};
typedef struct dlink node;
node *start = NULL;
node *newnode, *temp;
node *getnode()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = newnode->prevAdd = NULL;
    return newnode;
}
void createList()
{
    char ch;
    do
    {
        newnode = getnode();
        if (start == NULL)
            start = newnode;
        else
        {
            temp = start;
            while (temp->nextAdd != NULL)
                temp = temp->nextAdd;
            temp->nextAdd = newnode;
            newnode->prevAdd = temp;
        }
        printf("\nWant to again (y/n) :");
        ch = getche();
    } while (ch == 'y' || ch == 'Y');
    printf("\nList created........");
}
void displayOddNo()
{
    printf("\nOdd elements are : ");
    temp = start;
    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
            printf("%5d", temp->data);
        temp = temp->nextAdd;
    }
    printf("\n");
}
int main()
{
    createList();
    displayOddNo(); // display odd no in a list
    return 0;
}