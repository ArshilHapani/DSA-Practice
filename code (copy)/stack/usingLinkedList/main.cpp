#include <iostream>
#include <memory>
using namespace std;

class Node
{
public:
    int data;
    shared_ptr<Node> next;

    Node(int data) : data(data), next(nullptr){};
};

class Stack
{

    shared_ptr<Node> top;

public:
    Stack() : top(nullptr){};

    bool isEmpty()
    {
        if (this->top == nullptr)
        {
            cout << "Stack Underflow\n";
            return true;
        }
        return false;
    }
    bool isFull()
    {
        try
        {
            shared_ptr<Node> sharedPtr = make_shared<Node>(42);
            return false;
        }
        catch (const bad_alloc &e)
        {
            cerr << "Memory allocation failed: " << e.what() << endl;
            return true;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            return;
        }
        shared_ptr<Node> current = this->top;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void push(int data)
    {
        if (isFull())
        {
            return;
        }
        shared_ptr<Node> newNode = make_shared<Node>(data);

        if (this->top == nullptr)
        {
            this->top = newNode; // pointing top to newNode
        }
        else
        {
            newNode->next = this->top; // adding element at the top of the linked list
            this->top = newNode;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        int data = this->top->data;
        this->top = this->top->next;
        return data;
    }

    int peek(int index)
    {
        shared_ptr<Node> current = this->top;
        int n = 1;
        while (n != index && current != nullptr)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Invalid Index\n";
            return 0;
        }
        return current->data;
    }

    int stackTop()
    {
        if (isEmpty())
        {
            return 0;
        }
        return this->top->data;
    }

    int stackBottom()
    {
        if (isEmpty())
        {
            return 0;
        }
        shared_ptr<Node> current = this->top;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current->data;
    }
};

int main(int argc, char const *argv[])
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Pooped element is " << s.pop() << endl;

    s.display();
    cout << "Peeked element is " << s.peek(3) << endl;
    cout << "StackBottom element is " << s.stackBottom() << endl;
    cout << "StackTop element is " << s.stackTop() << endl;
    return 0;
}
