#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    char *data;
    int top;
    int size;
};

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}
int isFull(struct Stack *s)
{
    return s->top - 1 == s->size;
}
void push(struct Stack *stack, char x)
{
    if (isFull(stack))
    {
        return;
    }
    stack->data[stack->top + 1] = x;
    stack->top++;
}
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return (char)0;
    }
    char data = stack->data[stack->top];
    stack->data[stack->top] = '\0';
    --stack->top;
    return data;
}
struct Stack *createStack(int size)
{
    struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));
    newStack->size = size;
    newStack->top = -1;
    newStack->data = (char *)malloc(size * sizeof(char));
    return newStack;
}
int matchParenthesis(char *p, int len)
{
    struct Stack *s = createStack(len);

    for (int i = 0; i < len; i++)
    {
        if (p[i] == '(' || p[i] == '[' || p[i] == '{')
        {
            push(s, p[i]);
        }
        else if (p[i] == ')' || p[i] == ']' || p[i] == '}')
        {
            if (isEmpty(s))
            {
                return 0;
            }

            char opening = pop(s);
            if ((p[i] == ')' && opening != '(') ||
                (p[i] == ']' && opening != '[') ||
                (p[i] == '}' && opening != '{'))
            {
                return 0;
            }
        }
    }
    printf("Stack status %d \n", isEmpty(s));
    free(s->data);
    return isEmpty(s);
    free(s);
}

int main(int argc, char const *argv[])
{
    const char *charString = "[a + b * {c] - (d / e)}";
    int len = strlen(charString);

    char charArray[len + 1];
    strcpy(charArray, charString);

    printf("Matching parenthesis for string %s is %s\n", charString, matchParenthesis(charArray, len) ? "balanced" : "unbalanced");
    return 0;
}
