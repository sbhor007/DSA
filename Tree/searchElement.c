#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Tree
{
    struct Tree *leftAdd;
    int data;
    struct Tree *rightAdd;
};
typedef struct Tree tree;
tree *root = NULL;
tree *newnode, *temp;

int menu()
{
    int ch;
    printf("\n1) Create. \n2)Display. \n3)search. \n4)Exit");
    printf("\n-------------------------\n");
    printf("\tEnter a Choice : ");
    scanf("%d", &ch);
    return ch;
}

tree *getnode()
{
    newnode = (tree *)malloc(sizeof(tree));
    printf("Enter data : ");
    scanf("%d", &newnode->data);
    newnode->leftAdd = newnode->rightAdd = NULL;
    return newnode;
}

tree *create(tree *root, tree *newnode)
{
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        if (newnode->data < root->data)
        {
            if (root->leftAdd == NULL)
            {
                root->leftAdd = newnode;
            }
            else
            {
                create(root->leftAdd, newnode);
            }
        }
        else if (newnode->data > root->data)
        {
            if (root->rightAdd == NULL)
            {
                root->rightAdd = newnode;
            }
            else
            {
                create(root->rightAdd, newnode);
            }
        }
        else if (newnode->data == root->data)
        {
            printf("\nDuplicate Elements are not allow....!");
        }
    }
    return root;
}

void display(tree *root)
{
    if (root != NULL)
    {
        display(root->leftAdd);
        printf("%5d", root->data);
        display(root->rightAdd);
    }
}
tree *search(tree *root, int key)
{
    if (root == NULL)
        return root;
    else if (root->data == key)
        return root;
    else if (root->data < key)
        search(root->rightAdd, key);
    else if (root->data > key)
        search(root->leftAdd, key);
}
int main()
{
    int key;
    char ch;
    while (1)
    {
        switch (menu())
        {
        case 1:
            do
            {
                newnode = getnode();
                root = create(root, newnode);
                printf("\nWant To Again (y/n) : ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            display(root);
            break;
        case 3:
            printf("\nEnter the element to search : ");
            scanf("%d", &key);

            search(root, key);
            if (search(root, key) != NULL)
            {
                printf("\nkey found");
            }
            else
            {
                printf("\nkey not found");
            }
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid input....!");
            break;
        }
    }
    return 0;
}