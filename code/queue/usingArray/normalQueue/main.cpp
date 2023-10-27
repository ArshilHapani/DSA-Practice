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
    void enqueue(int data)
    {
        if (isFull())
            return;
        this->rear++;
        this->arr[this->rear] = data;
    }
    int dequeue()
    {
        if (isEmpty())
            return -1;
        this->front += 1;
        int data = this->arr[this->front];
        this->arr[this->front] = '\0';
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
    int peek(int index)
    {
        return this->arr[index - 1];
    }
    int queueTop()
    {
        return this->arr[this->front + 1];
    }
    int queueBottom()
    {
        return this->arr[this->rear];
    }
    ~Queue()
    {
        delete this->arr;
    }
};

int main(int argc, char const *argv[])
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Dequeued element " << q.dequeue() << endl;
    cout << "Dequeued element " << q.dequeue() << endl;
    cout << "Dequeued element " << q.dequeue() << endl;
    cout << "Peek element 4 " << q.peek(4) << endl;
    cout << "Queue bottom " << q.queueBottom() << endl;
    cout << "Queue top " << q.queueTop() << endl;

    q.display();
    return 0;
}
