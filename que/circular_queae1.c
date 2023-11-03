#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5
int front = -1, rear = -1;

void insert(int a[], int no)
{
    // check overflow condition
    if ((rear + 1) % MAX == front)
    {
        printf("\nQue is Overflow");
    }
    else
    {
        if (rear == -1 && front == -1)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        a[rear] = no;
        printf("\nelement inserted...");
    }
}

void delete_q(int a[])
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueae is empty....!");
    }
    else
    {
        int n = a[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        printf("\nDeleted Element is : %d", n);
    }
}

void display(int a[])
{
    if (rear == -1 && front == -1)
    {
        printf("\nQueae is empty.....");
    }
    else
    {
        printf("\nQueae elements is : ");
        for (int i = front; i != rear + 1; i = (i + 1) % 10)
        {
            printf("%5d", a[i]);
        }
    }
}

int menu()
{
    int ch;
    printf("\n****** Circular Que Menu******\n");
    printf("\n1. Insert\n2. delete\n3. Display\n4. exit");
    printf("\nEnter choise : ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    int que[MAX], no;
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nEnter a Number : ");
            scanf("%d", &no);
            insert(que, no);
            break;
        case 2:
            delete_q(que);
            break;
        case 3:
            display(que);
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid input...!");
            break;
        }
    }
}