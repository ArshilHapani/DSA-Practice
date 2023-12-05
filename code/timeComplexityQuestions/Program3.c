#include <stdio.h>
#include <stdlib.h>

int random(int n)
{
    int num = (int)rand() % (n + 1);
    return num;
}
int myFn(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        int i = random(n - 1);
        printf("this\n");
        return myFn(i) + myFn(n - 1 - i);
    }
}

int main()
{
    myFn(6);
}