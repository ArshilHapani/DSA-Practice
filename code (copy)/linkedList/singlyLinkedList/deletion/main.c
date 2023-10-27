#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *temp = head;
    head = temp->next;
    free(temp);
    return head;
}

void deleteLastNode(struct Node *head)
{
    struct Node *lastNode = head->next;
    struct Node *prevLastNode = head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
        prevLastNode = prevLastNode->next;
    }
    prevLastNode->next = NULL;
    free(lastNode);
}

void deleteNodeByValue(struct Node *head, int value)
{
    struct Node *node_to_find = head->next;
    struct Node *prev_node = head;

    while (node_to_find->data != value && node_to_find->next != NULL)
    {
        node_to_find = node_to_find->next;
        prev_node = prev_node->next;
    }

    prev_node->next = node_to_find->next;
    free(node_to_find);
}

void deleteNodeByIndex(struct Node *head, int index)
{
    struct Node *node_to_find = head->next;
    struct Node *prev_node = head;
    int n = 0;
    while (n != index - 2)
    {
        node_to_find = node_to_find->next;
        prev_node = prev_node->next;
        n++;
    }

    prev_node->next = node_to_find->next;
    free(node_to_find);
}

void deleteNodeNextToOtherNode(struct Node *node, struct Node *prevNode)
{
    prevNode->next = node->next;
    free(node);
}
void deleteNodeByGivenNode(struct Node *head, struct Node *node)
{
    struct Node *current = head->next;
    struct Node *previous = head;

    while (current != node)
    {
        current = current->next;
        previous = previous->next;
    }
    previous->next = node->next;
    free(node);
}

struct Node *createNode()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

int main(int argc, char const *argv[])
{
    struct Node *head = createNode();
    struct Node *second = createNode();
    struct Node *third = createNode();
    struct Node *fourth = createNode();
    struct Node *fifth = createNode();
    struct Node *sixth = createNode();
    struct Node *seven = createNode();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = sixth;

    sixth->data = 60;
    sixth->next = seven;

    seven->data = 70;
    seven->next = NULL;

    head = deleteFirstNode(head);
    deleteLastNode(head);
    deleteNodeByValue(head, 40);
    deleteNodeByIndex(head, 3);
    deleteNodeNextToOtherNode(sixth, third);
    deleteNodeByGivenNode(head, third);
    display(head);
    return 0;
}
