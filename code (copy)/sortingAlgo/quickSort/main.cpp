#include <iostream>
using namespace std;

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
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
    int arr[] = {1, 56, 4, 5, 7, 4, 8, 10};
    int length = sizeof(arr) / sizeof(int);
    display(arr, length);
    quickSort(arr, 0, length - 1);
    display(arr, length);
    return 0;
}
