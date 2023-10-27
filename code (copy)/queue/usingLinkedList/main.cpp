#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr){};
};

class Queue
{
private:
    Node *front, *rear;

    bool isEmpty()
    {
        return this->front == nullptr && this->rear == nullptr;
    }

public:
    Queue() : front(nullptr), rear(nullptr){};

    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (newNode == nullptr)
        {
            cout << "Failed to create node\n";
            return;
        }
        if (isEmpty())
        {
            this->front = this->rear = newNode;
        }
        this->rear->next = newNode;
        this->rear = newNode;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow\n";
            exit(EXIT_FAILURE);
        }
        Node *current = this->front;
        int data = current->data;
        this->front = current->next;
        delete current;
        return data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue underflow\n";
            exit(EXIT_FAILURE);
        }
        Node *current = this->front;
        while (current != nullptr)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Dequeued element is " << q.dequeue() << endl;
    cout << "Dequeued element is " << q.dequeue() << endl;
    cout << "Dequeued element is " << q.dequeue() << endl;
    cout << "Dequeued element is " << q.dequeue() << endl;
    cout << "Dequeued element is " << q.dequeue() << endl;
    q.display();
    return 0;
}
