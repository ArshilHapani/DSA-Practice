#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class Stack
{
private:
    std::unique_ptr<T[]> arr;
    int size;
    int top;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = std::make_unique<T[]>(size);
    }

    void display()
    {
        for (int i = 0; i < this->top + 1; i++)
        {
            cout << this->arr[i] << endl;
        }
    }

    bool isEmpty()
    {
        if (this->top == -1)
        {
            cout << "Stack underflow\n";
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (this->top == this->size - 1)
        {
            cout << "Stack overflow\n";
            return true;
        }
        return false;
    }

    void push(T val)
    {
        if (isFull())
        {
            return;
        }
        this->top++;
        this->arr[this->top] = val;
    }

    T pop()
    {
        if (isEmpty())
        {
            return (T)0;
        }
        T temp = arr[this->top];
        this->arr[top] = (T)0;
        this->top--;
        return temp;
    }

    T peek(int index)
    {
        if (isEmpty())
        {
            return (T)0;
        }
        if (index > this->size)
        {
            cout << "Index is out of bound\n";
            return (T)0;
        }
        return this->arr[index];
    }
};

int main(int argc, char const *argv[])
{
    Stack<int> s(5);
    for (int i = 1; i < 6; i++)
    {
        s.push(i);
    }

    int poppedElement = s.pop();
    cout << "Pooped element " << poppedElement << endl;

    s.display();
    cout << "Peeked Element = " << s.peek(2) << endl;
    return 0;
}
