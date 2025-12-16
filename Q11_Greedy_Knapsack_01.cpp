#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
    double ratio;
};

int knapsack01Greedy(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end(),
         [](Item &a, Item &b)
         {
             return a.ratio > b.ratio;
         });

    int totalValue = 0;

    for (int i = 0; i < items.size() && capacity > 0; i++)
    {
        if (items[i].weight <= capacity)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
    }
    return totalValue;
}

int main()
{
    int itemCount, capacity;
    cin >> itemCount >> capacity;

    vector<Item> items(itemCount);
    for (int i = 0; i < itemCount; i++)
    {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    int result = knapsack01Greedy(items, capacity);
    cout << result << endl;

    return 0;
}