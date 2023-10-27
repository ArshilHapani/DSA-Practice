/**
 * This file contain code for merge sort
 */

#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int low, int mid, int high)
{
    int i, j, k;
    // int b[high - low + 1];
    i = low;
    j = mid + 1;
    k = low;
    int *b = (int *)malloc(high - low + 1 * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
    free(b);
}

void mergeSort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {23, 4, 5, 22, 76, 9, 3};
    int length = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, length - 1);
    display(arr, length);
    return 0;
}
