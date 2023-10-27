#include <iostream>
#include <memory>

using namespace std;

class Queue
{
public:
    int rear;
    int front;
    int size;
    int *arr;

    Queue(int size)
    {
        this->rear = this->front = -1;
        this->size = size;
        this->arr = new int[size];
    }
    bool isFull()
    {
        return this->rear == this->size - 1;
    }
    bool isEmpty()
    {
        return this->rear == this->front;
    }
    void enqueueR(int data)
    {
        if (isFull())
            return;
        this->rear++;
        this->arr[this->rear] = data;
    }
    void enqueueF(int data)
    {
        if (this->front == -1)
        {
            cout << "Can't add element from front\n";
            return;
        }
        this->arr[this->front] = data;
        this->front--;
    }
    int dequeueF()
    {
        if (isEmpty())
            return -1;
        this->front += 1;
        int data = this->arr[this->front];
        this->arr[this->front] = '\0';
        return data;
    }
    int dequeueR()
    {
        if (isEmpty())
            return -1;
        int data = this->arr[this->rear];
        this->arr[this->rear] = '\0';
        this->rear -= 1;
        return data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = 0; i < this->size; i++)
        {
            cout << this->arr[i] << endl;
        }
    }
    ~Queue()
    {
        delete this->arr;
    }
};

int main(int argc, char const *argv[])
{
    Queue q(5);
    q.enqueueR(10);
    q.enqueueR(20);
    q.enqueueR(30);
    q.enqueueR(40);
    q.enqueueR(50);

    cout << "Dequeued element from front " << q.dequeueF() << endl;

    q.enqueueF(5);
    cout << "Dequeued element from Rear " << q.dequeueR() << endl;

    q.display();
    return 0;
}
