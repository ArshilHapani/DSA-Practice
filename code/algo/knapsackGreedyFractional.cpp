#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// item class to store the profit and weight of the item
class Item
{
public:
    int weight;
    int profit;

    Item(int weight, int profit) : weight(weight), profit(profit){};
};

class FractionalKnapsackUtil
{
    static bool compare(Item a, Item b)
    {
        // sorting function which sort the items on the basis of ratio
        double ratioA = a.profit / a.weight;
        double ratioB = b.profit / b.weight;
        return ratioA > ratioB;
    }

public:
    double fractionalKnapsack(vector<Item> items, int maxWeight, string type = "pw")
    {
        // sorting items on the basis of different knapsack type criteria
        if (type == "pw")
            sort(items.begin(), items.end(), compare); // using static method for better readability
        else if (type == "p")
            sort(items.begin(), items.end(), [](Item a, Item b)
                 { return a.profit > b.profit; }); // using profit
        else if (type == "w")
            sort(items.begin(), items.end(), [](Item a, Item b)
                 { return a.weight > b.weight; }); // using weight

        double finalProfit = 0;

        for (Item &item : items)
        {
            if (maxWeight >= item.weight)
            {
                finalProfit += item.profit;
                maxWeight -= item.weight;
            }
            else
            {
                finalProfit += (double)maxWeight / item.weight * item.profit;
                break;
            }
        }
        return finalProfit;
    }
};

int main()
{
    FractionalKnapsackUtil util;
    vector<Item> items = {{3, 10}, {3, 15}, {2, 10}, {5, 12}, {1, 8}}; // vector of items consist {w,p}
    int totalWeight = 10;
    cout << "Maximum profit using p/w ratio: " << util.fractionalKnapsack(items, totalWeight, "pw") << endl;
    cout << "Maximum profit using w: " << util.fractionalKnapsack(items, totalWeight, "w") << endl;
    cout << "Maximum profit using p: " << util.fractionalKnapsack(items, totalWeight, "p") << endl;
    return 0;
}