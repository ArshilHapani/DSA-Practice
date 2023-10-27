#include <stdio.h>

void display(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high; // tracking value of i and j
    int temp;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int *arr, int low, int high)
{
    int partitionIndex; // index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);  // sorting right part of array
        quickSort(arr, partitionIndex + 1, high); // sorting left part of array
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {23, 4, 5, 22, 76, 9, 3};
    int length = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, length - 1);
    display(arr, length);
    return 0;
}
