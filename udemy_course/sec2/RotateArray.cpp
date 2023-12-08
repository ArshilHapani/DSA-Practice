#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();
    k %= n;

    vector<int> tempArr(n);

    for (int i = 0; i < n; ++i)
    {
        tempArr[(i + k) % n] = arr[i];
    }
    arr = tempArr;
}

void reverseL(vector<int> &arr, int start, int end)
{
    reverse(arr.begin() + start, arr.begin() + end + 1);
}

void smartRotate(vector<int> &arr, int k)
{
    k %= arr.size();
    reverseL(arr, 0, arr.size() - 1);
    reverseL(arr, 0, k - 1);
    reverseL(arr, k, arr.size() - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 3;
    rotateArray(arr, k);

    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}