#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Stack
{
public:
    unique_ptr<char[]> c;
    int top;
    int size;

    bool isEmpty()
    {
        return this->top == -1;
    }

    bool isFull()
    {
        return this->top - 1 == size;
    }

    void push(char data)
    {
        if (isFull())
        {
            cout << "Stack overflow\n";
            return;
        }
        this->c[this->top + 1] = data;
        this->top++;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            return '\0';
        }
        char d = this->c[this->top];
        this->c[this->top] = '\0';
        this->top--;
        return d;
    }

    Stack(int stackSize)
    {
        this->c = make_unique<char[]>(stackSize);
        this->top = -1;
        this->size = stackSize;
    }
};

bool matchParenthesis(const string &s)
{
    int len = s.length();
    unique_ptr<Stack> newStack = make_unique<Stack>(len);

    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
        {
            newStack->push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (newStack->isEmpty())
            {
                return false;
            }
            char opening = newStack->pop();
            if ((c == ')' && opening != '(') ||
                (c == ']' && opening != '[') ||
                (c == '}' && opening != '{'))
            {
                return 0;
            }
        }
    }

    return newStack->isEmpty();
}
int main(int argc, char const *argv[])
{
    const string s = "[a + b * {c] - (d / e)}";
    cout << matchParenthesis(s) << endl;
    return 0;
}
