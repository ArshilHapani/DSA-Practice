#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isFull(struct CircularQueue *q)
{
    if ((q->rear + 1) % q->size == q->front) // or rear >= size - 1 && front == 0
    {
        printf("Queue overflow\n");
        return 1;
    }
    return 0;
}
int isEmpty(struct CircularQueue *q)
{
    if (q->rear == q->front)
    {
        printf("Queue underflow\n");
        return 1;
    }
    return 0;
}
void display(struct CircularQueue *q)
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

struct CircularQueue *createQueue(int size)
{
    struct CircularQueue *newQueue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    newQueue->front = newQueue->rear = 0;
    newQueue->size = size;
    newQueue->arr = (int *)malloc(size * sizeof(int));

    return newQueue;
}
void enqueue(struct CircularQueue *q, int data)
{
    if (isFull(q))
    {
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = data;
}
int dequeue(struct CircularQueue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    q->front = (q->front + 1) % q->size;
    int val = q->arr[q->front];
    q->arr[q->front] = '\0';
    return val;
}

int peek(struct CircularQueue *q, int pos)
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
int queueTop(struct CircularQueue *q)
{
    return q->arr[q->front + 1];
}
int queueBottom(struct CircularQueue *q)
{
    return q->arr[q->rear];
}

int main(int argc, char const *argv[])
{
    struct CircularQueue *q1 = createQueue(5); // space 0 is reserved for f and r

    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 40);

    dequeue(q1);
    dequeue(q1);
    dequeue(q1);

    enqueue(q1, 60);
    enqueue(q1, 70);
    enqueue(q1, 80);

    dequeue(q1);
    dequeue(q1);
    dequeue(q1);

    display(q1);

    free(q1->arr);
    free(q1);
    return 0;
}