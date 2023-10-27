#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int rear;
    int front;
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
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc((size) * sizeof(int));
    return q;
}
void enqueueR(struct Queue *q, int data)
{
    if (isFull(q))
    {
        return;
    }
    q->rear += 1;
    q->arr[q->rear] = data;
}
void enqueueF(struct Queue *q, int data)
{

    if (q->front == -1)
    {
        printf("Cannot insert element at front\n");
        return;
    }
    q->arr[q->front] = data;
    q->front -= 1;
}
int dequeueF(struct Queue *q)
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
int dequeueR(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    int val = q->arr[q->rear];
    q->arr[q->rear] = '\0';
    q->rear -= 1;
    return val;
}

int main(int argc, char const *argv[])
{
    struct Queue *q = createQueue(5);
    enqueueR(q, 10);
    enqueueR(q, 20);
    enqueueR(q, 30);
    enqueueR(q, 40);
    enqueueR(q, 50);

    dequeueF(q);
    dequeueF(q);

    enqueueF(q, 10);
    enqueueF(q, 5);

    printf("dequeued from rear element %d\n", dequeueR(q));
    printf("dequeued from rear element %d\n", dequeueR(q));

    display(q);
    return 0;
}
