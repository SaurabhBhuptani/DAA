#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
    double ratio;
};

double fractionalKnapsackGreedy(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end(),
         [](Item &a, Item &b)
         {
             return a.ratio > b.ratio;
         });

    double totalValue = 0.0;

    for (int i = 0; i < items.size() && capacity > 0; i++)
    {
        if (items[i].weight <= capacity)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            totalValue += items[i].ratio * capacity;
            capacity = 0;
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

    double result = fractionalKnapsackGreedy(items, capacity);
    cout << result << endl;

    return 0;
}