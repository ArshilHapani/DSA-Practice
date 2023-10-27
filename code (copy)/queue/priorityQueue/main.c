#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int data;
    int priority;
};

void sortArray(struct Element *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = arr[i].priority;
        int pos = i;
        struct Element *temp;

        for (int j = 0; j < size; j++)
        {
            if (arr[j].priority < min)
            {
                min = arr[j].priority;
                pos = j;
            }
        }
        // temp = arr[i];
        // arr[i] = arr[pos];
        // TODOs
    }
}

struct Element *createPQueue(int size)
{
    struct Element **arrayOfElement = (struct Element *)malloc(size * sizeof(struct Element));
    return arrayOfElement;
}
