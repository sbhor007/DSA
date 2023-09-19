#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct linkedList
{
    int data;
    struct linkedList *next;
};
typedef struct linkedList node;
node *start = NULL;

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
    printf("\n11) Search");
    printf("\n12 swap nth and mth element");
    printf("\n-----------------------------");
    printf("\n13) exit.");
    printf("\n-------------------------------");
    printf("\nEnter a Choise : ");
    scanf("%d", &no);
    return no;
}
node *getnode()
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

void createList(int no)
{
    node *newnode;
    node *temp;
    for (int i = 1; i <= no; i++)
    {
        newnode = getnode();
        if (start == NULL)
            start = newnode;
        else
        {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    printf("\nList created");
    getch();
}
int counter()
{
    int ctr = 0;
    node *temp = start;
    while (temp != NULL)
    {
        ctr++;
        temp = temp->next;
    }
    return ctr;
}
void insertFirst()
{
    node *newnode = getnode();
    if (start == NULL)
        start = newnode;
    else
    {

        newnode->next = start;
        start = newnode;
    }
    printf("\nEliment inserted at first position.");
    getch();
}
void insertLast()
{
    node *newnode = getnode();
    node *temp;
    if (start == NULL)
        start = newnode;
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("\nElement inserted at last Position");
    getch();
}
void display()
{
    node *temp = start;
    printf("\nList Data are : ");
    if (start == NULL)
        printf("Empty.....!");
    else
    {
        while (temp != NULL)
        {
            printf("%5d", temp->data);
            temp = temp->next;
        }
    }
    getch();
}
void insertMiddle()
{
    node *newnode, *prev, *temp;
    int i, pos, ctr;
    printf("Enter the position to insert element : ");
    scanf("%d", &pos);
    ctr = counter();
    if (pos > 0 && pos <= ctr)
    {
        newnode = getnode();
        temp = start;
        for (i = 0; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = newnode;
        newnode->next = temp;
        printf("\nElement inserted successfully.");
    }
    else
    {
        printf("\ninvalid position.");
    }
    getch();
}
void deleteFirst()
{
    node *temp = start;
    if (start != NULL)
    {
        start = temp->next;
        printf("\nDeleted Element is : %d", temp->data);
        free(temp);
        printf("\nElememt deleted successfully.");
        getch();
    }
    else
    {
        printf("\nList not exist");
        getch();
    }
}
void deleteLast()
{
    node *temp, *prev;
    if (start != NULL)
    {
        temp = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("\nDeleted Element is : %d", temp->data);
        free(temp);
        printf("\nElememt deleted successfully.");
        getch();
    }
    else
    {
        printf("\nList not exist.");
        getch();
    }
}
void deleteMiddle()
{
    node *temp, *prev;
    int i, pos, ctr = counter();
    if (start != NULL)
    {
        printf("\nEnter the Position to delete element : ");
        scanf("%d", &pos);
        if (pos > 0 && pos <= ctr)
        {
            temp = start;
            i = 1;
            while (i < pos)
            {
                prev = temp;
                temp = temp->next;
                i++;
            }
            prev->next = temp->next;
            printf("\nDeleted element is : %d", temp->data);
            free(temp);
            printf("\nElememt deleted successfully.");
            getch();
        }
        else
        {
            printf("\ninvalid position.");
            getch();
        }
    }
    else
    {
        printf("\nList Not Exist.");
        getch();
    }
}
void reverseList()
{
    node *a[500];
    node *temp = start;
    int i = 0;
    if (start != NULL)
    {
        while (temp != NULL)
        {
            a[i] = temp;
            temp = temp->next;
            i++;
        }
        i--;
        while (i >= 0)
        {
            printf("%5d", a[i]->data);
            i--;
        }
        getch();
    }
    else
    {
        printf("\n lisr data are : Empty...!");
        getch();
    }
}
int search(key)
{
    int flag = 0;
    node *temp = start;
    if(start != NULL)
    {
        while(temp != NULL)
            {
                if(temp->data == key)
                    return flag = 1;
                temp = temp->next;
            }
    }
    return flag;
}
void swap()
{
    node *nth, *mth, *temp;
    int t, ctr = counter();
    int n, m;
    if (start == NULL)
    {
        printf("\nEmpty List.......");
    }
    else
    {
        printf("\nEnter a first element position : ");
        scanf("%d", &m);
        if (m > 0 && m <= ctr)
        {
            printf("\nEnter the second element position : ");
            scanf("%d", &n);
            if (n > 0 && n <= ctr && m != n)
            {
                m--, n--; // alwas  start position. travel loop properly
                nth = start;
                for (int i = 1; i <= n; i++)
                    nth = nth->next;
                mth = start;
                for (int j = 1; j <= m; j++)
                    mth = mth->next;

                t = nth->data;
                nth->data = mth->data;
                mth->data = t;
                printf("\n Swaping compleated......");
            }
            else
            {
                printf("\ninvalid position");
            }
        }
        else
        {
            printf("\ninvalid position");
        }
    }
    getch();
}
int main()
{
    int no,result,key;
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nHow many elements in a list : ");
            scanf("%d", &no);
            createList(no);
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
            deleteFirst();
            break;
        case 6:
            deleteLast();
            break;
        case 7:
            deleteMiddle();
            break;
        case 8:
            printf("\nNo of List elements is : %d", counter());
            getch();
            break;
        case 9:
            display();
            break;
        case 10:
            reverseList();
            break;
        case 11:
            printf("\nEnter element to search : ");
            scanf("%d",&key);
            result = search(key);
            if(result == 1)
                printf("\nElement Found.");
            else
                printf("\nElement Not Found.");
            break;
        case 12:
            swap();
        default:
            exit(0);
        }
    }
    return 0;
}
