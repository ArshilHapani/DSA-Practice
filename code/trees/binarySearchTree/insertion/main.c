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
struct Node *insertRec(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insertRec(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertRec(root->right, data);
    }
    return root;
}
void insert(struct Node *root, int data)
{
    root = insertRec(root, data);
}
void inOrderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}
int main(int argc, char const *argv[])
{

    struct Node *root = createNode(5);
    root->left = appendLeft(root, 3);
    root->right = appendRight(root, 6);

    appendLeft(root->left, 1);
    appendRight(root->left, 4);
    insert(root, 12);
    insert(root, 2);
    inOrderTraversal(root);
    printf("\n");
    freeBinaryTree(root);
    return 0;
}
