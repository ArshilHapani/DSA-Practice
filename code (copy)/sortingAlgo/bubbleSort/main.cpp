#include <iostream>

using namespace std;

void display(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int *a, int len)
{
    int temp, isSorted = 0;
    for (int i = 0; i < len - 1; i++)
    {
        isSorted = 1;
        cout << "Working on pass " << i + 1 << endl;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {34, 46, 53, 264, 242, 552, 46, 21};
    // int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);
    bubbleSort(arr, len);
    display(arr, len);
    return 0;
}
