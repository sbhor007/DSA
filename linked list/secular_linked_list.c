#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct clink
{
    int data;
    struct clink *nextAdd;
};
typedef struct clink node;
node *start = NULL;
node *temp, *newnode, *next, *prev;
node *getnode()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
    return newnode;
}
int counter()
{
    int ctr = 0;
    temp = start;
    if (start == NULL)
        printf("\nList not exist...");
    {
        do
        {
            temp = temp->nextAdd;
            ctr++;
        } while (temp != start);
    }
    return ctr;
}
void createlist(int no)
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
        }
    }
    newnode->nextAdd = start;
}
void insertFirst()
{
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
        newnode->nextAdd = start;
    }
    else
    {
        temp = start;
        while (temp->nextAdd != start)
        {
            temp = temp->nextAdd;
        }
        newnode->nextAdd = start;
        start = newnode;
        temp->nextAdd = start;
    }
    printf("\n Node inserted.....");
}

void insertLast()
{
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
        newnode->nextAdd = start;
    }
    else
    {
        temp = start;
        while (temp->nextAdd != temp)
        {
            temp = temp->nextAdd;
        }
        temp->nextAdd = newnode;
        newnode->nextAdd = start;
    }
}

void insertMiddle()
{
    int pos;
    if (start == NULL)
    {
        printf("\nList Not found....");
    }
    else
    {
        printf("\nEntere the position to insert node (1 - %d) : ", counter());
        scanf("%d", &pos);
        if (pos > 1 && pos <= counter())
        {
            newnode = getnode();
            temp = start;
            for (int i = 1; i < pos; i++)
            {
                prev = temp;
                temp = temp->nextAdd;
            }
            prev->nextAdd = newnode;
            newnode->nextAdd = temp;
            printf("\n%d inserted at %d position.", newnode->data, pos);
        }
        else if (pos == 1)
        {
            insertFirst();
        }
        else if (pos == counter() + 1)
            insertLast();
        else
        {
            printf("\nInvalid Position.....");
        }
    }
}

void display()
{
    temp = start;
    printf("\nlist data are : ");
    if (start == NULL)
        printf("Empty.....!");
    else
    {
        do
        {
            printf("%5d", temp->data);
            temp = temp->nextAdd;
        } while (temp != start);
    }
}

int menu()
{
    int no;
    printf("\n1) Create List.");
    printf("\n----------------------------");
    printf("\n2) insert node at first.");
    printf("\n3) insert node at last.");
    printf("\n4) insert node at Middle.");
    printf("\n----------------------------");
    printf("\n5) Delete at first node.");
    printf("\n6) Delete at Last node.");
    printf("\n7) Delete at Middele node.");
    printf("\n-----------------------------");
    printf("\n8) Count nodes.");
    printf("\n9) Display List.");
    printf("\n10) reverse List.");
    printf("\n-----------------------------");
    printf("\n11) exit.");
    printf("\n-------------------------------");
    printf("\nEnter a Choise : ");
    scanf("%d", &no);
    return no;
}

int main()
{
    int no;
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nHow many elements in a list : ");
            scanf("%d", &no);
            createlist(no);
            break;
        case 2:
            insertFirst();
            break;
        case 3:
            insertLast();
            break;
        case 4:
            insertMiddle();
            break;
        case 5:
            // deleteFirst();
            break;
        case 6:
            // deleteLast();
            break;
        case 7:
            // deleteMiddle();
            break;
        case 8:
            printf("\nNo of List elements is : %d", counter());
            break;
        case 9:
            display();
            break;
        case 10:
            // reverseList();
            break;
        case 11:
            exit(0);
        default:
            printf("\nInvalid input...!");
        }
    }
    return 0;
}
