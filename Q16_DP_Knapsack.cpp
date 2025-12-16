#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> knapsack01(vector<int> &wt, vector<int> &val, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Reconstruct selected items
    vector<int> items;
    int w = W;
    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            items.push_back(i); // item index 1-based
            w -= wt[i - 1];
        }
    }
    reverse(items.begin(), items.end());
    return {dp[n][W], items};
}

int main()
{
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};
    int capacity = 7;

    auto res = knapsack01(weights, values, capacity);

    cout << "Maximum Value: " << res.first << "\n";
    cout << "Selected item indices: ";
    for (int idx : res.second)
        cout << idx << " ";
    cout << "\n";

    return 0;
}