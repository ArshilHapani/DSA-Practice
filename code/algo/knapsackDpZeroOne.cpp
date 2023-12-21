#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item
{
public:
    int weight;
    int profit;

    Item(int weight, int profit) : weight(weight), profit(profit){};
};

class ZeroOneKnapsack
{
public:
    int zeroOneRecFn(int capacity, int index, vector<Item> &items, vector<vector<int>> &memoizationMatrix)
    {
        if (index == 0 || capacity == 0)
            return 0;

        if (memoizationMatrix[index][capacity] != -1)
        {
            return memoizationMatrix[index][capacity];
        }

        if (items[index - 1].weight > capacity)
        {
            memoizationMatrix[index][capacity] = zeroOneRecFn(capacity, index - 1, items, memoizationMatrix);
        }
        else
        {
            int val1 = items[index - 1].profit + zeroOneRecFn(capacity - items[index - 1].weight, index - 1, items, memoizationMatrix); // pick item
            int val2 = zeroOneRecFn(capacity, index - 1, items, memoizationMatrix);                                                     // don't pick item
            memoizationMatrix[index][capacity] = max(val1, val2);
        }

        return memoizationMatrix[index][capacity];
    }
    int knapsack(vector<Item> items, int capacity)
    {
        sort(items.begin(), items.end(), [](const Item &a, const Item &b)
             { return a.weight < b.weight; });

        int n = items.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= capacity; j++)
            {
                if (items[i - 1].weight <= j)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].weight] + items[i - 1].profit);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][capacity];
    }
};

int main()
{
    ZeroOneKnapsack knapsack;
    vector<Item> items = {{18, 30}, {15, 21}, {10, 18}};

    int capacity = 30;
    cout << "iterative approach:  " << knapsack.knapsack(items, capacity) << endl;
    int n = items.size();
    vector<vector<int>> memoMatrix(n + 1, vector<int>(capacity + 1, -1));
    cout << "recursive approach:  " << knapsack.zeroOneRecFn(capacity, n, items, memoMatrix) << endl;
    return 0;
}