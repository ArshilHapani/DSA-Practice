#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr){};
};

class List
{
    Node *head;

public:
    List() : head(nullptr){};

    Node *append(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->head->next = this->head;
            this->head->prev = this->head;
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
            newNode->prev = current;
            this->head->prev = newNode;
        }
        return newNode;
    }

    void display()
    {
        Node *current = this->head;
        do
        {
            cout << "(" << (current->prev == nullptr ? 0 : current->prev->data) << "," << current->data << ")"
                 << "->";
            current = current->next;
        } while (current != this->head);
        cout << "(head," << current->data << ")" << endl;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == nullptr)
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            this->head = newNode;
            return;
        }
        Node *tail = this->head->prev;
        newNode->next = this->head;
        newNode->prev = tail;

        this->head->prev = newNode;
        tail->next = newNode;

        this->head = newNode;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        Node *current = this->head;
        while (current->next != this->head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->next = this->head;
        this->head->prev = newNode;
    }

    void insertAtSpecificIndex(int data, int index)
    {
        Node *newNode = new Node(data);
        Node *current = this->head;
        int n = 0;

        while (n != index - 1 && current->next != this->head)
        {
            current = current->next;
            n++;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        if (newNode->next != this->head)
        {
            // changing next node previous which points at *current node
            newNode->next->prev = newNode;
        }
    }

    void deleteFirstNode()
    {
        Node *current = this->head;
        this->head->prev->next = this->head->next;
        this->head->next->prev = this->head->prev;
        this->head = this->head->next;
        delete current;
    }

    void deleteLastNode()
    {
        Node *current = this->head;
        while (current->next != this->head)
        {
            current = current->next;
        }
        current->prev->next = this->head;
        this->head->prev = current->prev;
        delete current;
    }

    void deleteNodeByIndex(int index)
    {
        Node *current = this->head;
        int n = 0;

        while (n != index - 1 && current->next != this->head)
        {
            current = current->next;
            n++;
        }
        if (current->next == this->head)
        {
            this->deleteLastNode();
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    void traversalBiDirection()
    {
        Node *current = this->head;
        cout << "\n";
        if (current->next == this->head)
        {
            cout << "List is empty \n";
        }
        Node *last = current->prev;
        do
        {
            cout << current->data << "->";
            current = current->next;
        } while (current != this->head);
        cout << "Ending->";
        do
        {
            cout << last->data << "->";
            last = last->prev;
        } while (last != this->head->prev);
        cout << "Starting\n";
    }
};

int main(int argc, char const *argv[])
{
    List l;

    l.append(10);
    l.append(20);
    l.append(30);

    l.insertAtBeginning(5);
    l.insertAtEnd(40);
    l.insertAtSpecificIndex(25, 3);

    l.deleteFirstNode();
    l.deleteLastNode();
    l.deleteNodeByIndex(3);

    l.display();
    l.traversalBiDirection();

    return 0;
}
