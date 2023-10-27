#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isFull(struct Queue *q)
{
    if (q->rear >= q->size - 1)
    {
        printf("Queue overflow\n");
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue *q)
{
    if (q->rear == q->front)
    {
        printf("Queue underflow\n");
        return 1;
    }
    return 0;
}
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        return;
    }
    for (int i = 0; i < q->size; i++)
    {
        printf("%d,", q->arr[i]);
    }
    printf("\n");
}

struct Queue *createQueue(int size)
{
    struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));
    newQueue->front = newQueue->rear = -1;
    newQueue->size = size;
    newQueue->arr = (int *)malloc(size * sizeof(int));

    return newQueue;
}
void enqueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        return;
    }
    q->rear += 1;
    q->arr[q->rear] = data;
}
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    q->front += 1;
    int val = q->arr[q->front];
    q->arr[q->front] = '\0';
    return val;
}

int peek(struct Queue *q, int pos)
{
    if (isEmpty(q))
    {
        return -1;
    }
    if (pos > q->size)
    {
        printf("Enter valid index\n");
        return -1;
    }
    return q->arr[pos - 1];
}
int queueTop(struct Queue *q)
{
    return q->arr[q->front + 1];
}
int queueBottom(struct Queue *q)
{
    return q->arr[q->rear];
}

int main(int argc, char const *argv[])
{
    struct Queue *q1 = createQueue(5);

    enqueue(q1, 10);
    enqueue(q1, 20);

    printf("Queue top is %d\n", queueTop(q1));
    printf("Dequeued element is %d\n", dequeue(q1));
    printf("Dequeued element is %d\n", dequeue(q1));
    enqueue(q1, 30);
    enqueue(q1, 40);
    enqueue(q1, 50);
    printf("Queue bottom is %d\n", queueBottom(q1));
    // enqueue(q1, 60); // i can't insert element in normal queue as it leads us to circular queue

    printf("Peeked element at position 4 is %d\n", peek(q1, 4));
    display(q1);
    free(q1->arr);
    free(q1);
    return 0;
}
/**
 There are two types of increment
 * Linear i = i+1
 * Circular i = (i+1) % size
*/