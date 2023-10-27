#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

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

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
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

int main(int argc, char const *argv[])
{
    struct Node *root = createNode(10);
    struct Node *lRoot = createNode(5);
    struct Node *rRoot = createNode(8);
    root->left = lRoot;
    root->right = rRoot;
    lRoot->left = createNode(3);
    lRoot->right = createNode(2);
    rRoot->right = createNode(20);
    rRoot->left = createNode(15);
    display(root, 0);
    freeBinaryTree(root);
    return 0;
}
