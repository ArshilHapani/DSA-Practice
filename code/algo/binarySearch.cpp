#include <iostream>

using namespace std;

void binarySearchRecursive(int arr[], int i, int j, int key)
{
    int mid = (i + j) / 2;
    if (i <= j)
    {

        if (arr[mid] == key)
        {
            cout << "Element found!\n";
            return;
        }
        else if (arr[mid] > key)
            binarySearchRecursive(arr, i, j - 1, key);
        else
            binarySearchRecursive(arr, mid + 1, j, key);
    }
    else
        cout << "Element does not exist in array \n";
}

void binarySearchIterative(int arr[], int i, int j, int key)
{

    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == key)
        {
            cout << "Element found!\n";
            return;
        }
        else if (arr[mid] > key)
            j = mid - 1;
        else if (arr[mid] < key)
            i = mid + 1;
    }

    cout << "element does not match key \n";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    binarySearchRecursive(arr, 1, 13, 25);
    binarySearchIterative(arr, 1, 13, 5);
    return 0;
}