#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "singlyLinkedListOperations.h"

int main(int argc, char const *argv[])
{
    struct Node *head = append(NULL, 10); // returns head
    append(head, 40);                     // returns new node
    append(head, 30);
    append(head, 5);
    append(head, 80);
    append(head, 12);
    append(head, 76);
    append(head, 1);
    display(head);
    sortList(&head);
    display(head);
    return 0;
}
