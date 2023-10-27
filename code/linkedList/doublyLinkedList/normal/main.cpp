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
        }
        else
        {
            Node *current = this->head;

            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = nullptr;
            newNode->prev = current;
        }
        return newNode;
    }

    void display()
    {
        Node *current = this->head;
        while (current != nullptr)
        {
            cout << "(" << (current->prev == nullptr ? 0 : current->prev->data) << "," << current->data << ")"
                 << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = this->head;
        this->head->prev = newNode;
        newNode->prev = nullptr;
        this->head = newNode;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        Node *current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->next = nullptr;
    }

    void insertAtSpecificIndex(int data, int index)
    {
        Node *newNode = new Node(data);
        Node *current = this->head;
        int n = 0;

        while (n != index - 1 && current != nullptr)
        {
            current = current->next;
            n++;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        if (newNode->next != nullptr)
        {
            // changing next node previous which points at *current node
            newNode->next->prev = newNode;
        }
    }

    void deleteFirstNode()
    {
        Node *current = this->head;
        this->head = this->head->next;
        this->head->prev = nullptr;
        delete current;
    }

    void deleteLastNode()
    {
        Node *current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        // converting last node into nullptr
        current->prev->next = nullptr;
        delete current;
    }

    void deleteNodeByIndex(int index)
    {
        Node *current = this->head;
        int n = 0;

        while (n != index - 1 && current != nullptr)
        {
            current = current->next;
            n++;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    void traversalBiDirection()
    {
        Node *current = this->head;
        cout << "\n";
        if (current == nullptr)
        {
            cout << "Something went wrong \n";
        }
        Node *last = current;
        while (last->next != nullptr)
        {
            last = last->next;
        }

        while (current != nullptr)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "Ending nullptr->";
        while (last != nullptr)
        {
            cout << last->data << "->";
            last = last->prev;
        }
        cout << "Starting nullptr \n";
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
    // l.deleteLastNode();
    // l.deleteNodeByIndex(3);

    l.display();
    l.traversalBiDirection();

    return 0;
}
