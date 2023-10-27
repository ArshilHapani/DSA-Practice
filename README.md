##### The DSA practice is done under the guidance of Code With Harry!
[Visit here](https://www.youtube.com/playlist?list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi)

## Circular Linked List in C

A circular linked list is a linked list in which the last node points to the first node. This creates a loop in the list, which makes it possible to traverse the list in either direction.

## Implementation

The following code implements a circular linked list in C. The `struct Node` represents a node in the list, and the `struct CircularLinkedList` represents the entire list.

```c
struct Node
{
    int data;
    struct Node *next;
};

struct CircularLinkedList
{
    struct Node *head;
};
```

The `createNode()` function creates a new node and returns a pointer to it.

```c
struct Node *createNode()
{
    return (struct Node *)malloc(sizeof(struct Node));
}
```

The `linkedListTraversal()` function traverses the linked list and prints the data of each node.

```c
void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;

    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("HEAD (%d)\n", ptr->data);
}
```

The `insertAtFirst()` function inserts a new node at the beginning of the linked list.

```c
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
```

The `insertAtLast()` function inserts a new node at the end of the linked list.

```c
void insertAtLast(struct Node *head, int data)
{
    struct Node *newNode = createNode();
    new
}
```