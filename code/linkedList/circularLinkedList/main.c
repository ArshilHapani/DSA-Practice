#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

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

void insertAtLast(struct Node *head, int data)
{
    struct Node *newNode = createNode();
    newNode->data = data;
    struct Node *ptr = head->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
}

void insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *current = head->next;
    struct Node *prev = head;
    struct Node *newNode = createNode();
    newNode->data = data;
    int n = 0;
    while (n != index - 1)
    {
        current = current->next;
        prev = prev->next;
        n++;
    }
    prev->next = newNode;
    newNode->next = current;
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *lastNode = head->next;
    struct Node *newHead = head->next;
    struct Node *oldHead = head;
    while (lastNode->next != head)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newHead;
    head = newHead;
    free(oldHead);
    return head;
}

void deleteLastNode(struct Node *head)
{
    struct Node *last = head->next;
    struct Node *secondLast = head;

    while (last->next != head)
    {
        last = last->next;
        secondLast = secondLast->next;
    }
    secondLast->next = head;
    free(last);
}

void deleteNodeByIndex(struct Node *head, int index)
{
    struct Node *current = head->next;
    struct Node *prev = head;
    int n = 0;
    while (n != index - 2)
    {
        current = current->next;
        prev = prev->next;
        n++;
    }
    prev->next = current->next;
    free(current);
}
int main()
{
    // creating head node in heap
    struct Node *head = createNode();
    struct Node *second = createNode();
    struct Node *third = createNode();
    struct Node *fourth = createNode();

    // creating first node and linking it with second node
    head->data = 10;
    head->next = second;

    // linking second node  with third node
    second->data = 20;
    second->next = third;

    // linking third node  with fourth node
    third->data = 30;
    third->next = fourth;

    // terminating the node at the end
    fourth->data = 40;
    fourth->next = head; // <- pointing last element to head instead of null

    head = insertAtFirst(head, 5);
    insertAtLast(head, 50);
    insertAtIndex(head, 6, 60);

    head = deleteFirstNode(head);
    deleteLastNode(head);
    deleteNodeByIndex(head, 3);

    linkedListTraversal(head);
    return 0;
}
