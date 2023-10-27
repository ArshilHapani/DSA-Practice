/**
 * This file contain merging procedure which require two sorted array and it merges that two arrays
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

int *merge(int *arr1, int *arr2, int len1, int len2)
{

    int *newArray = (int *)malloc(len1 + len2 * sizeof(int));
    int i, j, k;
    i = j = k = 0;
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            newArray[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            newArray[k] = arr2[j];
            j++;
            k++;
        }
    }

    while (i < len1)
    {
        newArray[k] = arr1[i];
        i++;
        k++;
    }
    while (j < len2)
    {
        newArray[k] = arr2[j];
        j++;
        k++;
    }

    return newArray;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {2, 5, 8, 12, 20};
    int arr2[] = {3, 6, 14, 23, 30};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    int *newArray = merge(arr1, arr2, len1, len2);
    display(newArray, len1 + len2);
    free(newArray);
    return 0;
}
