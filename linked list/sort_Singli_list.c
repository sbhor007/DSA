// write a 'C' program to sort elements of a singly linked list in ascending order and display the sorted list;
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct singlilist
{
    int data;
    struct singlilist *nextAdd;
};
typedef struct singlilist node;
node *start = NULL;
node *newnode, *temp, *next, *prev;
node *getnode()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
    return newnode;
}
void createList()
{
    char ch;
    do
    {
        newnode = getnode();
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->nextAdd != NULL)
                temp = temp->nextAdd;
            temp->nextAdd = newnode;
        }
        printf("\nWant To Again (y/n): ");
        ch = getche();
    } while (ch == 'y' || ch == 'Y');
    printf("\nList Created.........");
}
void display()
{
    temp = start;
    printf("\nList Data Are : ");
    if (start == NULL)
        printf("Empty......");
    else
    {
        while (temp != NULL)
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        }
        printf("\n");
    }
}
void bsort()
{
    for (temp = start; temp->nextAdd != NULL; temp = temp->nextAdd)
    {
        for (next = temp->nextAdd; next != NULL; next = next->nextAdd)
        {
            if (temp->data > next->data)
            {
                int t = temp->data;
                temp->data = next->data;
                next->data = t;
            }
        }
    }
}
int main()
{
    createList();
    printf("\nOriginal list");
    display();
    // sort linked list
    bsort();
    printf("\nSorted list\n");
    display();
    return 0;
}