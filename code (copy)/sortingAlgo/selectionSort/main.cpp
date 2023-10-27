#include <iostream>

using namespace std;
void display(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionSort(int *a, int size)
{
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {23, 4, 5, 22, 76, 9, 3};
    int length = sizeof(arr) / sizeof(int);
    selectionSort(arr, length);
    display(arr, length);
    return 0;
}
