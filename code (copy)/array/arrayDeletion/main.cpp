#include <iostream>
#include <stdlib.h>
using namespace std;

class Deletion
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
    void deleteAtSpecificIndex(int *arr, int size, int index)
    {
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
};
int main(int argc, char const *argv[])
{
    int arr[10];
    int size = argc - 1;
    for (int i = 0; i < size; i++)
    {
        arr[i] = atoi(argv[i + 1]);
    }
    Deletion d;
    d.display(arr, size);
    d.deleteAtSpecificIndex(arr, size, 2);
    size -= 1;
    d.display(arr, size);

    return 0;
}
