#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateArray(vector<int> &arr, int k)
{
    reverse(arr.begin(), arr.end());

    reverse(arr.begin(), arr.end() + k);

    reverse(arr.begin() + k, arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 2;
    rotateArray(arr, k);

    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}