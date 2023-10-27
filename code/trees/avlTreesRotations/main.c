#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height; // height of the tree in order to calculate bf
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    newNode->height = 1;
    return newNode;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int getHeight(struct Node *root)
{
    if (root != NULL)
        return 0;
    return root->height;
}

int getBalanceFactor(struct Node *node)
{
    if (node == NULL)
    {
        return 1;
    }
    return getHeight(node->left) - getHeight(node->right);
}

struct Node *rightRotate(struct Node *rNode)
{
    struct Node *n1 = rNode->left;
    struct Node *n2 = rNode->right;

    n1->right = rNode;
    rNode->right = n2;

    rNode->height = max(getHeight(rNode->right), getHeight(rNode->left)) + 1;
    n1->height = max(getHeight(n1->right), getHeight(n1->left)) + 1;

    return n1;
}

struct Node *leftRotate(struct Node *lNode)
{
    struct Node *n1 = lNode->right;
    struct Node *n2 = n1->left;

    n1->left = lNode;
    lNode->right = n2;

    lNode->height = max(getHeight(lNode->right), getHeight(lNode->left)) + 1;
    n1->height = max(getHeight(n1->right), getHeight(n1->left)) + 1;

    return n1;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    // left left case
    if (bf > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    // right right case
    if (bf < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }

    // left right case
    if (bf > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right left case
    if (bf < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 15);
    inOrderTraversal(root);
    printf("\n");
    return 0;
}
