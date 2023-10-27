#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Graph
{
    int v;             // number of vertices
    struct Node **adj; // Array of linked list
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*----------------------------for queue-----------------------------------------*/
struct Queue
{
    struct Node *rear;
    struct Node *front;
};

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

/*---------------------------------------------------------------------*/

/*
    @param v number of vertices for your derived graph
*/
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->v = vertices;
    graph->adj = (struct Node **)malloc(vertices * sizeof(struct Node *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adj[i] = NULL;
    }
    return graph;
}
/*
    @param graph Graph instance
    @param src source node position
    @param dest destination node position

*/
void addEdge(struct Graph *graph, int src, int dest)
{
    // edge between src to destination
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adj[src];

    // edge between destination to src
    newNode = createNode(src);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

/*
    @param startVertex the vertex from which you want to start traversal
*/
void BFS(struct Graph *graph, int startVertex)
{
    bool *visited = (bool *)malloc(graph->v * sizeof(bool));
    for (int i = 0; i < graph->v; i++)
    {
        visited[i] = false;
    }

    struct Queue *q = createQueue();

    visited[startVertex] = true;
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node *temp = graph->adj[currentVertex];
        while (temp)
        {
            int adjacentVertex = temp->data;
            if (!visited[adjacentVertex])
            {
                visited[adjacentVertex] = true;
                enqueue(q, adjacentVertex);
            }
            temp = temp->next;
        }
    }

    free(visited);
}

int main()
{
    int v = 5;
    struct Graph *graph = createGraph(v);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);

    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);

    addEdge(graph, 2, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    addEdge(graph, 3, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);

    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);

    addEdge(graph, 5, 4);

    addEdge(graph, 6, 4);

    printf("BSF from v0: \n");
    BFS(graph, 0);
    printf("\n");

    return 0;
}