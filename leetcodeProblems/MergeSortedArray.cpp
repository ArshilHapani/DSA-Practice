#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp;
        for (int i = 0; i < m; i++)
        {
            temp.push_back(nums1.at(i));
        }
        for (int i = 0; i < n; i++)
        {
            temp.push_back(nums2.at(i));
        }

        nums1 = temp;
        sort(nums1.begin(), nums1.end());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v1 = {1, 2, 3, 4, 0, 0, 0};
    vector<int> v2 = {1, 2, 3, 4, 0, 0, 0};

    s.merge(v1, 4, v2, 4);

    for (int item : v1)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
