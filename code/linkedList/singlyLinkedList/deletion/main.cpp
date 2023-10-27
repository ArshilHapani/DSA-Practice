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

    Node *append(int data)
    {
        Node *newNode = new Node(data);

        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            Node *current = this->head; /* code */

            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        return newNode;
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

    void deleteFirstNode()
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        Node *next = this->head;
        this->head = head->next;
        delete next;
    }

    void deleteLastNode()
    {
        Node *lastNode = this->head->next;
        Node *secondLast = this->head;
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
            secondLast = secondLast->next;
        }
        secondLast->next = nullptr;
        delete lastNode;
    }

    void deleteNodeByValue(int value)
    {
        Node *findValue = this->head->next;
        Node *beforeNode = this->head;
        while (findValue->data != value && findValue->next != nullptr)
        {
            findValue = findValue->next;
            beforeNode = beforeNode->next;
        }
        if (findValue->data != value)
        {
            cout << "Element does not exist in the list" << endl;
            return;
        }
        beforeNode->next = findValue->next;
        delete findValue;
    }

    void deleteNodeByIndex(int index)
    {
        Node *findValue = this->head->next;
        Node *beforeNode = this->head;
        int n = 0;
        while (n != index - 1)
        {
            findValue = findValue->next;
            beforeNode = beforeNode->next;
            n++;
        }
        beforeNode->next = findValue->next;
        delete findValue;
    }

    void deleteNodeByNode(Node *node, Node *prevNode)
    {
        prevNode->next = node->next;
        delete node;
    }
    void deleteByNode(Node *node)
    {
        Node *current = this->head->next;
        Node *prev = this->head;

        while (current != node)
        {
            current = current->next;
            prev = prev->next;
        }
        prev->next = node->next;
        delete node;
    }
};

int main(int argc, char const *argv[])
{
    List l;
    l.append(10);
    Node *n1 = l.append(20);
    Node *n2 = l.append(30);
    l.append(40);
    Node *n3 = l.append(50);
    l.append(60);
    l.append(70);

    l.deleteFirstNode();
    l.deleteLastNode();
    l.deleteNodeByValue(40);
    l.deleteNodeByIndex(3);
    l.deleteNodeByNode(n2, n1);
    l.deleteByNode(n3);
    l.display();
    return 0;
}
