#include <iostream>
using namespace std;

class SortingFns
{

public:
    void display(int arr[], int n)
    {
        // Traversal
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    bool insertAtSpecificIndex(int *arr, int *pSize, int *pElement, int *pIndex, int *pTotalSize)
    {
        int size = *pSize, element = *pElement, index = *pIndex, totalSize = *pTotalSize;
        if (size >= totalSize)
        {
            return false;
        }
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        return true;
    }
    void insertOnSortedArray(int *arr, int *pSize, int *pElement, int *pTotalSize)
    {
        int size = *pSize, element = *pElement, totalSize = *pTotalSize;
        int i = size - 1;
        while (i > 0 && arr[i] > element)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = element;
    }
};
int main(int argc, char const *argv[])
{
    int arr[10] = {2, 3, 1};
    int size = 3, totalSize = 10, element = 4, index = 1;
    SortingFns sf;
    sf.insertAtSpecificIndex(arr, &size, &element, &index, &totalSize);
    size += 1;
    sf.display(arr, size);
    int newArr[10] = {1, 3, 6, 8};
    sf.insertOnSortedArray(newArr, &size, &element, &totalSize);
    size += 1;
    cout << "\nElement inserted on sorted array\n";
    sf.display(newArr, size);
    return 0;
}
