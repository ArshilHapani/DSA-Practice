#include <iostream>
#include <memory>

using namespace std;

class CircularQueue
{
public:
    int size;
    int front;
    int rear;
    unique_ptr<int[]> arr;

    CircularQueue(int size)
    {
        this->size = size + 1;
        this->front = this->rear = -1;
        this->arr = make_unique<int[]>(size + 1);
    }
    bool isEmpty()
    {
        return this->rear == this->front;
    }
    bool isFull()
    {
        return (this->rear + 1) % this->size == this->front;
    }
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue overflow\n";
            return;
        }
        this->rear = (this->rear + 1) % this->size;
        this->arr[this->rear] = data;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow\n";
            return -1;
        }
        this->front = (this->front + 1) % this->size;
        int val = this->arr[this->front];
        this->arr[this->front] = '\0';
        return val;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue underflow\n";
            return;
        }
        for (int i = 0; i < this->size; i++)
        {
            cout << this->arr[i] << ",";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    CircularQueue c(5);
    c.enqueue(10);
    c.enqueue(20);
    c.enqueue(30);
    c.enqueue(40);
    c.enqueue(50);

    c.dequeue();
    c.dequeue();
    c.dequeue();
    c.dequeue();

    c.enqueue(10);
    c.enqueue(20);
    c.enqueue(30);
    c.enqueue(40);

    c.display();
    return 0;
}
