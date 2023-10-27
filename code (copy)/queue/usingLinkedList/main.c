#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *rear;
    struct Node *front;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int isEmpty(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue underflow\n");
        return 1;
    }
    return 0;
}

struct Queue *createQueue()
{
    struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}
void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = createNode(data);
    if (q->front == NULL && q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        return;
    }
    struct Node *current = q->front;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        exit(EXIT_FAILURE);
    }
    struct Node *current = q->front;
    int data = current->data;
    q->front = current->next;
    free(current);
    return data;
}
int main(int argc, char const *argv[])
{
    struct Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Dequeued element is %d \n", dequeue(q));
    printf("Dequeued element is %d \n", dequeue(q));
    printf("Dequeued element is %d \n", dequeue(q));
    printf("Dequeued element is %d \n", dequeue(q));

    display(q);
    free(q);
    return 0;
}
