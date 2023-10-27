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
int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        // if left sub tree is not bst then return
        if (!isBST(root->left))
        {
            return 0;
        }
        // for first node prev is NULL and after that the data of current root must be less than previous node data
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int main(int argc, char const *argv[])
{

    struct Node *root = createNode(5);
    root->left = appendLeft(root, 3);
    root->right = appendRight(root, 6);

    appendLeft(root->left, 1);
    appendRight(root->left, 4);

    display(root, 0);
    printf("\n");
    inOrderTraversal(root);

    printf("\n%d\n", isBST(root));
    freeBinaryTree(root);
    return 0;
}
