#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct dynamicStack
{
    int data;
    struct dynamicStack *nextAdd;
};
typedef struct dynamicStack stack;
stack *top = NULL;
stack *newnode, *temp;

int menu()
{
    int ch;
    printf("\n*******MENU*********");
    printf("\n1) Push.\n2) Pop.\n3) Display.\n4) Exit.");
    printf("\nEnter Your Choise : ");
    scanf("%d", &ch);
    return ch;
}

stack *getnode()
{
    newnode = (stack *)malloc(sizeof(stack));
    printf("\nEnter Data : ");
    scanf("%d", &newnode->data);
    newnode->nextAdd = NULL;
    return newnode;
}

void push()
{
    newnode = getnode();
    if (top == NULL)
        top = newnode;
    else
    {
        newnode->nextAdd = top;
        top = newnode;
    }
    printf("\nInsertion successfull.....");
}
void display()
{
    printf("\nStack data are : ");
    if (top == NULL)
        printf("Empty......!");
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->nextAdd;
        }
        printf("NULL");
    }
}

void pop()
{
    if (top == NULL)
        printf("\nStack is empty.....!!");
    else
    {
        temp = top;
        top = top->nextAdd;
        printf("\nDeleted element is %d", temp->data);
        free(temp);
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

            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}