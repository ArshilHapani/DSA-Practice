#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Failed to assign memory\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("(%d,%d)->", current->prev == NULL ? 0 : current->prev->data, current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node *insertNodeAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = NULL;
    head = newNode;

    return head;
}

void insertAtTheEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *current = head;
    if (head == NULL)
    {
        head = newNode;
        head->next = NULL;
        head->prev = NULL;
        return;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    newNode->next = NULL;
}

void insertAtSpecificIndex(struct Node *head, int data, int index)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *current = head;
    int n = 0;
    while (n != index - 1 && current->next != NULL)
    {
        current = current->next;
        n++;
    }
    if (current->next == NULL)
    {
        printf("Enter the valid index \n");
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *temp = head;
    head->next->prev = NULL;
    head = temp->next;
    free(temp);
    return head;
}

void deleteLastNode(struct Node *head)
{
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}

void deleteNodeByIndex(struct Node *head, int index)
{
    struct Node *current = head;
    int n = 0;

    while (n != index - 1 && current != NULL)
    {
        current = current->next;
        n++;
    }
    if (current == NULL)
    {
        printf("Enter valid index\n");
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

void traversalBiDirectionNal(struct Node *head)
{
    struct Node *current = head;

    if (current == NULL)
    {
        printf("Empty linked list");
        return;
    }
    struct Node *end = current;
    while (end->next != NULL)
    {
        end = end->next;
    }

    printf("\nNULL->");
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("END->");
    while (end != NULL)
    {
        printf("%d->", end->data);
        end = end->prev;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    struct Node *head = createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);
    struct Node *fourth = createNode(40);

    head->next = second;

    second->next = third;
    second->prev = head;

    third->next = fourth;
    third->prev = second;

    fourth->next = NULL;
    fourth->prev = third;

    head = insertNodeAtBeginning(head, 5);
    insertAtTheEnd(head, 50);
    insertAtSpecificIndex(head, 25, 3);

    head = deleteFirstNode(head);
    deleteLastNode(head);
    deleteNodeByIndex(head, 3);

    display(head);
    traversalBiDirectionNal(head);
    return 0;
}
