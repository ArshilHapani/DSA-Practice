#include <iostream>
#include <cstring>

class Stack
{
private:
    char *data;
    int top;
    int size;

public:
    Stack(int _size) : size(_size), top(-1)
    {
        data = new char[size];
    }

    ~Stack()
    {
        delete[] data;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top + 1 == size;
    }

    void push(char value)
    {
        if (isFull())
        {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        top++;
        data[top] = value;
    }

    char pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack underflow" << std::endl;
            return '\0';
        }
        char value = data[top];
        data[top] = '\0';
        top--;
        return value;
    }

    char stackTop()
    {
        return data[top];
    }
};

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isOpeningParenthesis(char c)
{
    return c == '(' || c == '{' || c == '[';
}

bool isClosingParenthesis(char c)
{
    return c == ')' || c == '}' || c == ']';
}

char *infixToPostfix(char *c, int len)
{
    Stack newStack(len);
    char *postFixExp = new char[len];
    int i = 0, j = 0;
    while (c[i] != '\0')
    {
        char currentChar = c[i];

        if (!isOperator(currentChar) && !isOpeningParenthesis(currentChar) && !isClosingParenthesis(currentChar))
        {
            postFixExp[j] = currentChar;
            j++;
            i++;
        }
        else if (isOpeningParenthesis(currentChar))
        {
            newStack.push(currentChar);
            i++;
        }
        else if (isClosingParenthesis(currentChar))
        {
            while (!newStack.isEmpty() && !isOpeningParenthesis(newStack.stackTop()))
            {
                postFixExp[j] = newStack.pop();
                j++;
            }
            newStack.pop(); // Popping ),],} whatever
            i++;
        }
        else
        {
            if (newStack.isEmpty() || precedence(currentChar) > precedence(newStack.stackTop()))
            {
                newStack.push(currentChar);
                i++;
            }
            else
            {
                postFixExp[j] = newStack.pop();
                j++;
            }
        }
    }

    while (!newStack.isEmpty())
    {
        postFixExp[j] = newStack.pop();
        j++;
    }
    return postFixExp;
}

int main()
{
    // const char *s = "{(a+b)*(c+d)}";
    const char *s = "k+l-m*n+(o^p)*w/u/v*t+q^j^a"; // kl+mn*-op^w*u/v/t*+qj^a^+
    int length = strlen(s);
    char infixString[length + 1];
    strcpy(infixString, s);
    char *postFixExp = infixToPostfix(infixString, length);
    std::cout << "PostFix = " << postFixExp << std::endl;

    delete[] postFixExp;
    return 0;
}
