#include <iostream>

using namespace std;

bool isArrMonotonic(int *arr, int len)
{
    bool increasing = true;
    bool decreasing = true;

    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            decreasing = false;
        }
        else if (arr[i + 1] < arr[i])
        {
            increasing = false;
        }
    }

    return increasing || decreasing;
}

int main()
{
    // int arr[] = {3, 3, 3};
    // int arr[] = {};
    // int arr[] = {3, 2, 2, 3, 1};
    int arr[] = {1, 3, 2, 4, 5};
    int len = sizeof(arr) / sizeof(int);
    cout << "Length " << len << endl;
    bool flg = isArrMonotonic(arr, len);
    cout << "Is array monotonic " << flg << endl;
}