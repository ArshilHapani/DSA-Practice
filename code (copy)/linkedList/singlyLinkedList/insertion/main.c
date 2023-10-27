#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    // creating new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    // assigning next of ptr to head and data
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    // creating new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1) // stopping the loop before the insertion index
    {
        p = p->next;
        i++;
    }

    /*
        d = data
        n = next
                   p
        --[d,n]--[d,n]--[d,n]--[d,n]--[d,n]...

                   p
        --[d,n]--[d,n]    [d,n]--[d,n]--[d,n]...
                      \  /
                      [d,n] -> ptr
    */
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node *insertAfterNode(struct Node *head, int data, struct Node *prevNode)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main(int argc, char const *argv[])
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 69;
    third->next = fourth;

    fourth->data = 30;
    fourth->next = NULL;

    // inserting at beginning
    printf("Before adding element at beginning\n");
    linkedListTraversal(head);
    struct Node *newHead = insertAtBeginning(head, 35);
    printf("After adding element at beginning\n");
    linkedListTraversal(newHead);
    printf("\n");

    // inserting at specific index
    printf("Before adding element at index 3 (between 20 and 69)\n");
    linkedListTraversal(newHead);
    newHead = insertAtIndex(newHead, 35, 3);
    printf("After adding element at index 3 (between 20 and 69)\n");
    linkedListTraversal(newHead);
    printf("\n");

    // inserting at end of linked list
    printf("Before adding element at the end\n");
    linkedListTraversal(newHead);
    newHead = insertAtEnd(newHead, 35);
    printf("After adding element at end\n");
    linkedListTraversal(newHead);
    printf("\n");

    // inserting after the given element
    printf("Before adding element after 20\n");
    linkedListTraversal(newHead);
    newHead = insertAfterNode(newHead, 35, second);
    printf("After adding element after 20\n");
    linkedListTraversal(newHead);
    printf("\n");

    return 0;
}
