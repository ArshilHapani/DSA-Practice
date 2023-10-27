#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *ptr;
};
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is underflow\n");
        return 1;
    }
    return 0;
}
int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack is overflow \n");
        return 1;
    }
    return 0;
}
void push(struct Stack *ptr, int data)
{
    if (isFull(ptr))
    {
        return;
    }
    ptr->ptr[ptr->top + 1] = data;
    ptr->top++;
}
int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return 0;
    }
    int val = ptr->ptr[ptr->top];
    ptr->ptr[ptr->top] = -1;
    ptr->top--;
    return val;
}
void printStack(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return;
    }
    for (int i = 0; i < ptr->top + 1; i++)
    {
        printf("%d\n", ptr->ptr[i]);
    }
}

struct Stack *createStack(int size)
{
    struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));
    if (newStack == NULL)
    {
        printf("Failed to allocate memory for stack\n");
        return NULL;
    }
    newStack->size = size;
    newStack->top = -1;
    newStack->ptr = (int *)malloc(newStack->size * sizeof(int));
    if (newStack->ptr == NULL)
    {
        printf("Failed to allocate memory for data\n");
        return NULL;
    }
    return newStack;
}

int peek(struct Stack *ptr, int index)
{
    if (isEmpty(ptr))
    {
        return 0;
    }
    if (index > ptr->size || index < -1)
    {
        printf("Index is out of bound\n");
        return 0;
    }
    return ptr->ptr[ptr->size - index];
}
int main(int argc, char const *argv[])
{
    struct Stack *s1 = createStack(5);

    push(s1, 10);
    push(s1, 20);
    push(s1, 30);
    push(s1, 40);
    push(s1, 50);

    printf("Deleted value from stack is %d\n", pop(s1));
    int index = 2;
    printf("\nValue at index %d is %d\n", index, peek(s1, index));
    printStack(s1);
    free(s1->ptr);
    return 0;
}
