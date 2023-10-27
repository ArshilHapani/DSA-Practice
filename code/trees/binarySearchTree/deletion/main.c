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
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            inOrderTraversal(root->left);
        }
        printf("%d ", root->data);
        if (root->right != NULL)
        {
            inOrderTraversal(root->right);
        }
    }
    else
    {
        printf("Tree is empty\n");
    }
}
struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct Node *deleteNode(struct Node *root, int data)
{
    struct Node *prev;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        prev = inOrderPredecessor(root);
        root->data = prev->data;
        root->left = deleteNode(root->left, prev->data);
    }
    return root;
}
int main(int argc, char const *argv[])
{

    struct Node *root = createNode(5);
    root->left = appendLeft(root, 3);
    root->right = appendRight(root, 6);

    appendLeft(root->left, 1);
    appendRight(root->left, 4);

    deleteNode(root, 4);
    inOrderTraversal(root);
    printf("\n");

    freeBinaryTree(root);
    return 0;
}
