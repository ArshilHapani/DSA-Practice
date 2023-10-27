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
// worst case o(n) best case o(log n)
struct Node *searchIter(struct Node *node, int key)
{
    while (node != NULL)
    {
        if (key == node->data)
        {
            return node;
        }
        else if (key < node->data)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return NULL;
}
int main(int argc, char const *argv[])
{

    struct Node *root = createNode(5);
    root->left = appendLeft(root, 3);
    root->right = appendRight(root, 6);

    appendLeft(root->left, 1);
    appendRight(root->left, 4);

    struct Node *keyedNode = searchIter(root, 12);
    if (keyedNode != NULL)
    {
        printf("Node address %d\n", keyedNode->data);
    }
    else
    {
        printf("Element not found\n");
    }
    freeBinaryTree(root);
    return 0;
}
