#include <bits/stdc++.h>
using namespace std;

// Naive string matching
// Finds all occurrences of pattern in text
void naivePatternSearch(const string &text, const string &pattern)
{
    int textLength = text.size();
    int patternLength = pattern.size();

    cout << "Pattern found at positions: ";

    for (int i = 0; i <= textLength - patternLength; i++)
    {
        int j;
        for (j = 0; j < patternLength; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == patternLength)
            cout << i << " ";
    }

    cout << endl;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    naivePatternSearch(s1, s2);

    return 0;
}