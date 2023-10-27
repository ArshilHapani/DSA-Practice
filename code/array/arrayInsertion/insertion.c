#include <stdio.h>

void display(int arr[], int n)
{
    // Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insertionAtGivenIndex(int arr[], int size, int element, int totalSize, int index)
{
    if (size >= totalSize)
    {
        return 0;
    }
    // Moving elements index
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int insertionOnSortedArray(int *arr, int *size, int *element, int *totalSize)
{
    int lSize = (*size), lElement = (*element), lTotalSize = (*totalSize);
    int i = lSize - 1;
    while (i > 0 && arr[i] > lElement)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = lElement;
    printf("\n");
    return 1;
}

int main()
{
    int arr[10] = {6, 9, 6};
    int size = 3, element = 9, index = 1;
    display(arr, size);
    printf("After inserting element %d at index %d\n", element, index);
    int result = insertionAtGivenIndex(arr, size, element, 10, index);
    size += 1;
    if (result == 1)
    {
        display(arr, size);
    }
    printf("\n\nSorted array insertion\n");
    int sortedArray[10] = {1, 4, 6, 7};
    int nSize = 4, nElement = 5, totalSize = 10;
    display(sortedArray, nSize);
    insertionOnSortedArray(sortedArray, &nSize, &nElement, &totalSize);
    nSize += 1;
    display(sortedArray, nSize);
    nSize += 1;
    return 0;
}
