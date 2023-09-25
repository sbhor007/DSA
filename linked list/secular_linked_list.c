#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct clink
{
    int data;
    struct clink *nextAdd;
};
typedef struct clink node;
node *start = NULL;
node *temp,*newnode,*next,*prev;
node *getnode()
{
    newnode = (node*) malloc (sizeof(node));
    printf("\nEnter data : ");
    scanf("%d",& newnode->data);
    newnode->nextAdd;
    return newnode;
}
void createlist(int no)
{
    for(int i=1; i<=no; i++)
    {
        newnode = getnode();
        if(start == NULL)
            start=newnode;
        else
        {
            temp = start;
            while(temp->nextAdd != NULL)
                temp = temp->nextAdd;
            temp->nextAdd = newnode;
        }
    }
    newnode->nextAdd=start;
}
void display ()
{
    temp = start;
    printf("\nlist data are : ");
    if(start == NULL)
        printf("Empty.....!");
    else
    {
        do {
            printf("%5d", temp->data);
            temp=temp->nextAdd;
        } while(temp != start);
    }
}
int main ()
{
createlist(5);
display();
return 0;
}
