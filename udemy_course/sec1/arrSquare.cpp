#include <iostream>
#include <math.h>

using namespace std;

int *bubbleSort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int temp, flag = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                flag = 1;
                cout << "Flag check\n";
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            if (flag == 0)
            {
                break;
            }
        }
    }
    return arr;
}

int *arrSquare(int *arr, int len)
{
    if (len == 0)
    {
        return arr;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = arr[i] * arr[i];
    }
    return bubbleSort(arr, len);
}

int *smartArraySquare(int *arr, int len)
{
    int *newArray = new int[len];
    int low = 0, high = len - 1;

    for (int i = len - 1; i >= 0; i--)
    {
        int leftElement = pow(arr[low], 2);
        int rightElement = pow(arr[high], 2);

        if (leftElement > rightElement)
        {
            newArray[i] = leftElement;
            low++;
        }
        else
        {
            newArray[i] = rightElement;
            high--;
        }
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = newArray[i];
    }
    delete newArray;
    return arr;
}

int main()
{
    int arr[] = {-3, -2, -1, 0, 2, 4, 8};
    int len = 7;
    smartArraySquare(arr, len);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}