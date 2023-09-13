#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct dlink
{
    int data;
    struct dlink *prevAdd, *nextAdd;
};
typedef struct dlink node;
node *start = NULL;
node *newnode, *temp, *next, *prev;

int menu()
{
    int no;
    printf("\n1) Create Doubly Linked List.");
    printf("\n----------------------------");
    printf("\n2) Insert First.");
    printf("\n3) Insert Last.");
    printf("\n4) Insert Middle.");
    printf("\n----------------------------");
    printf("\n5) Delete First.");
    printf("\n6) Delete Last.");
    printf("\n7) Delete Middle.");
    printf("\n----------------------------");
    printf("\n8) Count node");
    printf("\n9) Traiverse left to right.");
    printf("\n10) Traiverse right to lrft.");
    printf("\n11) Search Element");
    printf("\n12) Sort List");
    printf("\n----------------------------");
    printf("\n13) Exit");
    printf("\n----------------------------");
    printf("\nEnter a Choice : ");
    scanf("%d", &no);
    return no;
}

node *getnode()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
    newnode->prevAdd = NULL;
    return newnode;
}

int count()
{
    int ctr = 1;
    for (temp = start; temp->nextAdd != NULL; temp = temp->nextAdd)
        ctr++;
    return ctr;
}

void createList(int no)
{

    for (int i = 1; i <= no; i++)
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
    }

    printf("\nList created.....");
}

void travalLeftToRight()
{
    temp = start;
    printf("\nList data are : ");
    if (start == NULL)
        printf("Empty.....!");
    else
    {
        while (temp != NULL)
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        }
    }
}

void TravelsRightToLeft()
{
    temp = start;
    printf("\nList Data in reverse order is : ");
    if (start == NULL)
        printf("Empty.......!");
    else
    {
        while (temp->nextAdd != NULL)
            temp = temp->nextAdd;
    }
    while (temp != NULL)
    {
        printf("%5d", temp->data);
        temp = temp->prevAdd;
    }
}

void insertFirst()
{
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
        printf("\nNode inserted at first position.");
    }
    else
    {
        newnode->nextAdd = start;
        start->prevAdd = newnode;
        start = newnode;
        printf("\nNode inserted at first position.");
    }
}

void insertLast()
{
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
        printf("\nNode inserted at Last position.");
    }
    else
    {
        temp = start;
        while (temp->nextAdd != NULL)
            temp = temp->nextAdd;
        temp->nextAdd = newnode;
        newnode->prevAdd = temp;
        printf("\nNode inserted at Last position.");
    }
}

void insertMiddle()
{
    int i, pos, ctr;
    if (start == NULL)
    {
        printf("\nInsertion not posible.");
        printf("\nEmpty is List....");
    }
    else
    {
        ctr = count();
        printf("\nEnter the position to insert : ");
        scanf("%d", &pos);
        if (pos > 1 && pos <= ctr)
        {
            newnode = getnode();
            temp = start;
            for (i = 2; i < pos; i++)
            {
                temp = temp->nextAdd;
            }
            prev = temp->prevAdd;
            newnode->prevAdd = prev;
            prev->nextAdd = newnode;
            newnode->nextAdd = temp;
            temp->prevAdd = newnode;
            printf("\nElement Inserted.");
        }
        else if (pos == 1)
            insertFirst();
        else
        {
            printf("\nInvalid Position.");
        }
    }
}

void deleteFirst()
{
    temp = start;
    start = temp->nextAdd;
    printf("\nDeleted Number is : %d ", temp->data);
    free(temp);
}

void deleteLast()
{
    temp = start;
    while (temp->nextAdd != NULL)
        temp = temp->nextAdd;
    prev = temp->prevAdd;
    prev->nextAdd = NULL;
    printf("\nDeleted element is : %d ", temp->data);
    free(temp);
}

void deleteMiddle()
{
    int i, pos, ctr;
    if (start == NULL)
    {
        printf("\nDeletion not posible.");
        printf("\nEmpty is List....");
    }
    else
    {
        ctr = count();
        printf("\nEnter the position to insert : ");
        scanf("%d", &pos);
        if (pos > 1 && pos <= ctr)
        {
            temp = start;
            for (i = 2; i < pos; i++)
            {
                temp = temp->nextAdd;
            }
            prev = temp->prevAdd;
            next = temp->nextAdd;
            prev->nextAdd = next;
            next->prevAdd = prev;
            printf("\nDeleted Element is : %d", temp->data);
            free(temp);
        }
        /*else if (pos == 1)
            deleteFirst();*/
        else
        {
            printf("\nInvalid Position.");
        }
    }
}

int main()
{
    int no;
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nHow many Elements to store : ");
            scanf("%d", &no);
            createList(no);
            getch();
            break;
        case 2:
            insertFirst();
            getch();
            break;
        case 3:
            insertLast();
            getch();
            break;
        case 4:
            insertMiddle();
            getch();
            break;
        case 5:
            deleteFirst();
            getch();
            break;
        case 6:
            deleteLast();
            getch();
            break;
        case 7:
            deleteMiddle();
            getch();
            break;
        case 8:
            printf("\nNO of List Elements is : %d", count());
            getch();
            break;
        case 9:
            travalLeftToRight();
            getch();
            break;
        case 10:
            TravelsRightToLeft();
            getch();
            break;
        case 11:
            break;
            case 12:
                break;
        default:
            exit(0);
        }
    }
}
