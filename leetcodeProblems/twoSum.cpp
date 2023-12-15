#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void twoSum(vector<int> arr, int target)
{
    pair<int, int> ans;
    unordered_map<int, int> tbl;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int requiredVal = target - arr[i];

        if (tbl.find(requiredVal) == tbl.end())
        {
            tbl[i] = arr[i];
        }
        else
        {
            auto it = tbl.find(requiredVal);
            int ansInd = it->first;
            ans = {ansInd, i};
        }
    }
}

int main()
{
}