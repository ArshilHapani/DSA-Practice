#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int maxScore(string s)
    {
        int maxS = 0;
        int leftZeroCtn = 0;
        int rightOneCtn = count(s.begin(), s.end(), '1');
        string s1;
        for (int i = 0; i < s.size() - 1; i++)
        {
            leftZeroCtn += (s[i] == '0');
            rightOneCtn -= (s[i] == '1');
            maxS = max(leftZeroCtn + rightOneCtn, maxS);
        }
        return maxS;
    }
};
int main()
{
    Solution s;
    cout << s.maxScore("00");
    return 0;
}