#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    char *data;
    int top;
    int size;
};
// Common stack utilities functions
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Stack *s)
{
    if (s->top + 1 == s->size)
    {
        return 1;
    }
    return 0;
}
struct Stack *createStack(int size)
{
    struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));
    newStack->size = size;
    newStack->top = -1;
    newStack->data = (char *)malloc((size) * sizeof(char));
    return newStack;
}
void push(struct Stack *s, char data)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = data;
}
char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return '\0';
    }
    char val = s->data[s->top];
    s->data[s->top] = '\0';
    --s->top;
    return val;
}
char stackTop(struct Stack *s)
{
    return s->data[s->top];
}

// infix to postfix fns
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

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return 1;
    }
    return 0;
}

int isOpeningParenthesis(char c)
{
    if (c == '(' || c == '{' || c == '[')
    {
        return 1;
    }
    return 0;
}
int isClosingParenthesis(char c)
{
    if (c == ')' || c == '}' || c == ']')
    {
        return 1;
    }
    return 0;
}

char *infixToPostfix(char *c, int len)
{
    struct Stack *newStack = createStack(len);
    char *postFixExp = (char *)malloc((len) * (sizeof(char)));
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
            push(newStack, currentChar);
            i++;
        }
        else if (isClosingParenthesis(currentChar))
        {
            while (!isEmpty(newStack) && !isOpeningParenthesis(stackTop(newStack)))
            {
                postFixExp[j] = pop(newStack);
                j++;
            }
            pop(newStack); // pooping ),],} whatever
            i++;
        }

        else
        {
            if (isEmpty(newStack) || precedence(currentChar) > precedence(stackTop(newStack)))
            {
                push(newStack, currentChar);
                i++;
            }
            else
            {
                postFixExp[j] = pop(newStack);
                j++;
            }
        }
    }

    while (!isEmpty(newStack))
    {
        postFixExp[j] = pop(newStack);
        j++;
    }
    free(newStack);
    return postFixExp;
}

int main(int argc, char const *argv[])
{
    const char *s = "{(a+b)*(c+d)}";
    // const char *s = "k+l-m*n+(o^p)*w/u/v*t+q^j^a"; // kl+mn*-op^w*u/v/t*+qj^a^+
    int length = strlen(s);
    char infixString[length + 1];
    strcpy(infixString, s);
    char *postFixExp = infixToPostfix(infixString, length);
    printf("PostFix = %s\n", postFixExp);

    free(postFixExp);
    return 0;
}
