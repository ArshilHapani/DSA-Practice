#include <stdio.h>

void display(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void insertionSort(int *arr, int length)
{
    int key, j;
    for (int i = 1; i <= length - 1; i++)
    {
        key = arr[i];
        j = i - 1; // previous element (5 then 23)
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {23, 4, 5, 22, 76, 9, 3};
    int length = sizeof(arr) / sizeof(int);
    insertionSort(arr, length);
    display(arr, length);
    return 0;
}
