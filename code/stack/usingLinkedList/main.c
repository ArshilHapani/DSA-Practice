#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is underflow\n");
        return 1;
    }
    return 0;
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    return newNode;
}

int isFull()
{
    struct Node *newNode = createNode(10);
    if (newNode == NULL)
    {
        printf("Stack overflow\n");
        return 1;
    }
    return 0;
}

void display(struct Node *s)
{
    struct Node *current = s;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

struct Node *push(struct Node *top, int data)
{
    if (isFull())
    {
        return NULL;
    }
    else
    {
        struct Node *newNode = createNode(data);
        newNode->next = top;
        top = newNode;
        return top;
    }
}
int pop(struct Node **top)
{
    struct Node *temp = *top;
    if (isEmpty(temp))
    {
        return 0;
    }
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}
int peek(struct Node *top, int index)
{
    struct Node *current = top;
    int i = 1;
    while (i != index && current != NULL)
    {
        current = current->next;
        i++;
    }
    if (current == NULL)
    {
        printf("Invalid index\n");
        return 0;
    }
    return current->data;
}

int stackBottom(struct Node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head->data;
}

int stackTop(struct Node *top)
{
    return top->data;
}

int main(int argc, char const *argv[])
{
    struct Node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    printf("popped element is %d\n", pop(&top));
    display(top);

    printf("Peeked element is %d\n", peek(top, 1));
    printf("StackBottom element is %d\n", stackBottom(top));
    printf("StackTop element is %d\n", stackTop(top));
    return 0;
}
