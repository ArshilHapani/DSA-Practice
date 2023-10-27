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

    int u;
    int i = 4;

    // array for visited node
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    // 7*7 adjacency matrix
    int adj[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1}};

    printf("Current element = %d\n", i);
    visited[i] = 1;
    enqueue(q, i);
    while (!isEmpty(q))
    {
        int node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (adj[node][j] == 1 && visited[j] == 0)
            {
                printf("Node: %d\n", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    return 0;
}
