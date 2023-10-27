#include <stdio.h>

void linearSearch(int *arr, int element, int length)
{
    int flag = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == element)
        {
            printf("%d found at position %d\n", element, i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("%d no such element exist in an array\n", element);
    }
}

int binarySearch(int *arr, int element, int length)
{
    int low = 0;
    int high = length - 1;
    // keep searching until low and high converges
    while (low <= high)
    {
        int mid = (int)(low + high) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[5] = {3, 45, 7, 8, 5};
    // shortcut to find size of arr
    int size = sizeof(arr) / sizeof(int); // as array is of int
    int element = 0;
    linearSearch(arr, element, size);
    int sortedArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index = binarySearch(sortedArray, element, 10);
    printf("%d is found at index %d\n", element, index);

    return 0;
}
