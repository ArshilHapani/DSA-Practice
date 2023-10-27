#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
void freeBinaryTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeBinaryTree(root->left);
    freeBinaryTree(root->right);
    free(root);
}
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;

    return newNode;
}

struct Node *appendRight(struct Node *node, int data)
{
    if (node->right != NULL)
    {
        printf("Right node is already occupied with data %d\n", node->right->data);
        return NULL;
    }
    struct Node *newNode = createNode(data);
    node->right = newNode;
    return newNode;
}
struct Node *appendLeft(struct Node *node, int data)
{
    if (node->left != NULL)
    {
        printf("Left node is already occupied with data %d\n", node->left->data);
        return NULL;
    }
    struct Node *newNode = createNode(data);
    node->left = newNode;
    return newNode;
}
void display(struct Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    display(root->right, level + 1);

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->data);

    display(root->left, level + 1);
}
void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            postOrderTraversal(root->left);
        }
        if (root->right != NULL)
        {
            postOrderTraversal(root->right);
        }
        printf("%d ", root->data);
    }
    else
    {
        printf("Tree is empty\n");
    }
}
int main(int argc, char const *argv[])
{

    struct Node *root = createNode(4);
    root->left = appendLeft(root, 1);
    root->right = appendRight(root, 6);

    appendLeft(root->left, 5);
    appendRight(root->left, 2);

    display(root, 0);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    freeBinaryTree(root);
    return 0;
}
