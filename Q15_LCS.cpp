#include <bits/stdc++.h>
using namespace std;

// Function to compute length of Longest Common Subsequence
int longestCommonSubsequence(const string &str1, const string &str2)
{
    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int lcsLength = longestCommonSubsequence(s1, s2);

    cout << "Length of LCS: " << lcsLength << endl;

    return 0;
}