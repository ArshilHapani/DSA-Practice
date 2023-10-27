#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // self referencing pointer
};

void linkedListTraversal(struct Node *node) // Pointer points at the head  node
{
    while (node != NULL)
    {
        printf("Data %d\n", node->data);
        node = node->next;
    }
}

int searchInLinkedList(struct Node *head, int element)
{
    struct Node *current = head;
    for (int i = 1; current->next != NULL; i++)
    {
        current = current->next;
        if (element == current->data)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    // creating head node in heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

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
    fourth->next = NULL;

    linkedListTraversal(head);
    int found = searchInLinkedList(head, 30);
    printf("Element 30 is found at %d index in linked list\n", found);
    return 0;
}
