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
    printf("\n1) create.\n2) inorder traiverse.\n3) preorder traiverse.\n4) postorder traiverse.\n5)Exit.");
    printf("\n-----------------------");
    printf("\nEnter Choice : ");
    scanf("%d", &ch);
    return ch;
}
tree *getnode()
{
    newnode = (tree *)malloc(sizeof(tree));
    printf("\nEnter Data : ");
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
    }
    return root;
}
tree *inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->leftAdd);
        printf("%5d", root->data);
        inorder(root->rightAdd);
    }
}
tree *postorder(tree *root)
{
    if (root != NULL)
    {
        postorder(root->leftAdd);
        postorder(root->rightAdd);
        printf("%5d", root->data);
    }
}
tree *preorder(tree *root)
{
    if (root != NULL)
    {
        printf("%5d", root->data);
        preorder(root->leftAdd);
        preorder(root->rightAdd);
    }
}
int main()
{
    int no;
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
                printf("\nWant to again (y/n): ");
                ch = getche();
            } while (ch == 'y' || ch == 'Y');
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
}
