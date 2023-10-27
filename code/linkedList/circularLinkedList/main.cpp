#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr){};
};

class List
{

    Node *head;

public:
    List() : head(nullptr){};

    Node *append(int value)
    {
        Node *newNode = new Node(value);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->head->next = this->head;
        }
        else
        {
            Node *current = this->head;
            while (current->next != this->head)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = this->head;
        }
        return newNode;
    }

    void display()
    {
        Node *current = this->head;
        do
        {
            cout << current->data << "->";
            current = current->next;
        } while (current != this->head);
        cout << " Head (" << current->data << ")" << endl;
    }

    // Insert at the beginning

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        Node *lastNode = this->head;

        while (lastNode->next != this->head)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = this->head;
        head = newNode;
    }

    // void inserting at specific index

    void insertAtSpecificIndex(int index, int value)
    {
        Node *newNode = new Node(value);
        Node *prevNode = this->head;
        int n = 0;
        while (n != index - 1)
        {
            prevNode = prevNode->next;
            n++;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    // inserting node at the end

    void insertAtEndOfList(int value)
    {
        Node *newNode = new Node(value);
        Node *lastNode = this->head->next;

        while (lastNode->next != this->head)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = this->head;
    }

    void deleteFirstNode()
    {
        Node *prev = this->head;
        while (prev->next != this->head)
        {
            prev = prev->next;
        }
        Node *temp = this->head;       // referencing temp node to head node
        this->head = this->head->next; // converting 2nd node as head node
        prev->next = this->head;       // pointing last node head to 2nd node (new head) node
        delete temp;
    }

    void deleteLastNode()
    {
        Node *lastNode = this->head->next;
        Node *prevLastNode = this->head;

        while (lastNode->next != this->head)
        {
            lastNode = lastNode->next;
            prevLastNode = prevLastNode->next;
        }
        prevLastNode->next = this->head;
        delete lastNode;
    }

    void deleteNodeByIndex(int index)
    {
        Node *nodeToDelete = this->head->next;
        Node *prevNode = this->head;
        int n = 0;
        while (n != index - 2)
        {
            nodeToDelete = nodeToDelete->next;
            prevNode = prevNode->next;
            n++;
        }
        prevNode->next = nodeToDelete->next;
        delete nodeToDelete;
    }
};

int main()
{
    List l;
    l.append(10);
    l.append(20);
    l.append(30);
    l.append(40);

    l.insertAtBeginning(5);
    l.insertAtSpecificIndex(3, 25);
    l.insertAtEndOfList(50);

    l.display();
    l.deleteFirstNode();
    l.deleteLastNode();
    l.deleteNodeByIndex(4);
    l.display();

    return 0;
}
