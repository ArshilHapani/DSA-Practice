#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
            }
            else
            {
                i++;
            }
        }

        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << s.removeElement(v, 2) << endl;
    for (int item : v)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}