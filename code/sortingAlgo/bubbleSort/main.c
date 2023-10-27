#include <stdio.h>

void display(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void bubbleSort(int *a, int size)
{
    int temp, isSorted = 0;
    for (int i = 0; i < size - 1; i++) // for number of pass
    {
        isSorted = 1;
        printf("Working on pass %d \n", i + 1);
        for (int j = 0; j < size - 1 - i; j++) // for comparison in each pass
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0; // first time checking for the sorted array means if we don't need to swap any element then array is sorted so return from the fn
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    // int a[] = {10, 35, 6, 22, 5, 32, 67, 9};
    int a[] = {5, 6, 9, 10, 22, 32, 35, 67};
    int length = sizeof(a) / sizeof(int);
    bubbleSort(a, length);
    display(a, length);
    return 0;
}
