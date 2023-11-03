#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct que
{
    int data[MAX];
    int front, rear;
};

void isInitial(struct que *q)
{
    q->front = -1;
    q->rear = -1;
}

void insert(struct que *q, int no)
{
    if ((q->rear + 1) % MAX == q->front)
    {
        printf("\nQueae is Overflow...!");
    }
    else
    {
        if (q->front == -1 && q->rear == -1)
        {
            q->front = 0;
            q->rear = 0;
        }
        else
        {
            q->rear = (q->rear + 1) % MAX;
        }
        q->data[q->rear] = no;
        printf("\nElement Inserted.....");
    }
}

void delete_q(struct que *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("\nQueae is Empty........!");
    }
    else
    {
        int no = q->data[q->front];
        if (q->front == q->rear)
        {
            isInitial(q);
        }
        else
        {
            q->front = (q->front + 1) % MAX;
        }
        printf("\nDeleted Element Is : %d", no);
    }
}

void display(struct que *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("\nQueae is empty....!");
    }
    else
    {
        printf("\nQueae Emelenets is : ");
        for (int i = q->front; i != q->rear+1; i = (i + 1) % MAX)
        {
            printf("%5d", q->data[i]);
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
    struct que queae;
    int no;
    isInitial(&queae);
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nEnter a Number : ");
            scanf("%d", &no);
            insert(&queae, no);
            break;
        case 2:
            delete_q(&queae);
            break;
        case 3:
            display(&queae);
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid input...!");
            break;
        }
    }
}