#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(const vector<int> &dims)
{
    int n = dims.size() - 1; // number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // l = chain length
    for (int l = 2; l <= n; ++l)
    {
        for (int i = 0; i <= n - l; ++i)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1]; // minimum cost to multiply all matrices
}

int main()
{
    vector<int> dims = {10, 30, 5, 60, 10};

    int minCost = matrixChainMultiplication(dims);

    cout << "Minimum number of multiplications: " << minCost << "\n";
    return 0;
}