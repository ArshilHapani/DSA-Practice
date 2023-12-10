#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &height)
    {
        int maxArea = 0;
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int minH = min(height[i], height[j]);
                int width = j - i;
                maxArea = max(maxArea, (minH * width));
            }
        }

        return maxArea;
    }

    int maxArea(vector<int> &height)
    {
        int area = 0;
        int left = 0, right = height.size() - 1;

        while (left < right)
        {
            int h = min(height[left], height[right]);
            int temp = h * (right - left);
            area = max(temp, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return area;
    }
};

int main()
{
    Solution s;
    // vector<int> v = {1, 1};
    vector<int> v = {3, 7, 5, 6, 8, 4};
    cout << s.maxArea(v) << endl;
    return 0;
}
