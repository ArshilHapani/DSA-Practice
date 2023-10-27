#include <iostream>
#include <climits>

void display(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int maximum(int *a, int len)
{
    int maxNum = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        if (maxNum < a[i])
        {
            maxNum = a[i];
        }
    }
    return maxNum;
}

void countSort(int *a, int len)
{
    int i, j;
    int maxNum = maximum(a, len) + 1;
    int *count = new int[maxNum](); // Initialized with zeros

    for (i = 0; i < len; i++)
    {
        count[a[i]]++;
    }

    i = 0;
    j = 0;

    while (i < maxNum)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    delete[] count;
}

int main()
{
    int arr[] = {23, 4, 5, 22, 76, 9, 3, 4};
    int length = sizeof(arr) / sizeof(int);
    countSort(arr, length);
    display(arr, length);
    return 0;
}
