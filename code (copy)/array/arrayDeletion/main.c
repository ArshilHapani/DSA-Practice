#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteElement(int *arr, int index, int size)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[10] = {1, 4, 5, 8, 6, 2};
    int size = 6;
    display(arr, size);
    deleteElement(arr, 4, 6);
    size -= 1;
    display(arr, size);
    return 0;
}
