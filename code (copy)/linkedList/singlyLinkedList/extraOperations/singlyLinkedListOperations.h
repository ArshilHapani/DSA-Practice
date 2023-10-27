#ifndef LINKED_LIST_UTILITY
#define SINGLY_LINKED_LIST_UTILITY

struct Node
{
    int data;
    struct Node *next;
};
/*display the linked list with it size
    @return size of the list
 */
int display(struct Node *head)
{
    struct Node *current = head;
    int n = 0;
    while (current != NULL)
    {
        printf("%d->", current->data);
        n++;
        current = current->next;
    }
    printf("NULL\nSize of stack is %d\n", n);
    return n;
}
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    return newNode;
}
/*append the new node at the end of the list, If the list is empty then it returns head
    @return newLy created node
    @param head if list is empty then NULL, else
*/
struct Node *append(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    else
    {
        struct Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
        return newNode;
    }
}

struct Node *merge(struct Node *left, struct Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    struct Node *finalNode = NULL;

    if (left->data <= right->data)
    {
        finalNode = left;
        finalNode->next = merge(left->next, right);
    }
    else
    {
        finalNode = right;
        finalNode->next = merge(left, right->next);
    }

    return finalNode;
}

/*sorting list using merge sort
    @return Updated head of the linked list
    @param head Current of the unsorted list
    @param size The size of linked list returned by display function
*/
void sortList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *left;
    struct Node *right;

    if (current == NULL || current->next == NULL)
        return;

    left = current;
    right = current->next;

    while (right != NULL && right->next != NULL)
    {
        left = left->next;
        right = right->next->next;
    }

    right = left->next;
    left->next = NULL;

    sortList(&left);
    sortList(&right);

    *head = merge(left, right);
}

#endif