#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class List
{
    Node *head;

public:
    List()
    {
        this->head = nullptr;
    }
    void display()
    {
        Node *current = this->head;
        while (current != nullptr)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    Node *append(int value)
    {
        Node *newNode = new Node(value);

        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            Node *current = this->head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        return newNode;
    }

    void appendAtStart(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
    }

    void appendAtEnd(int data)
    {
        Node *newNode = new Node(data);
        Node *endNode = this->head;
        while (endNode->next != nullptr)
        {
            endNode = endNode->next;
        }
        endNode->next = newNode;
        newNode->next = nullptr;
    }

    void appendAtSpecificIndex(int data, int index)
    {
        Node *newNode = new Node(data);
        Node *previousNode = this->head;
        int i = 0;
        while (i != index - 1)
        {
            previousNode = previousNode->next;
            i++;
        }
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }

    void appendAfterSpecificNode(int data, Node *n)
    {
        Node *newNode = new Node(data);
        newNode->next = n->next;
        n->next = newNode;
    }
};

int main(int argc, char const *argv[])
{
    List l;
    Node *n = l.append(10);
    l.append(20);
    l.append(30);
    l.appendAtStart(5);
    l.appendAtEnd(40);
    l.appendAtSpecificIndex(25, 3);
    l.appendAfterSpecificNode(15, n);
    l.display();
    return 0;
}
