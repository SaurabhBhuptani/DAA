#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp Algorithm for Pattern Matching
// Finds all occurrences of pattern in text
void rabinKarpSearch(const string &text, const string &pattern, int prime = 101)
{
    int n = text.size();
    int m = pattern.size();
    int base = 256; // Number of possible characters

    long long patternHash = 0;
    long long textHash = 0;
    long long h = 1;

    // The value of base^(m-1) % prime
    for (int i = 0; i < m - 1; i++)
        h = (h * base) % prime;

    // Calculate initial hash values for pattern and first window of text
    for (int i = 0; i < m; i++)
    {
        patternHash = (patternHash * base + pattern[i]) % prime;
        textHash = (textHash * base + text[i]) % prime;
    }

    cout << "Pattern found at positions: ";

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++)
    {
        // Check the hash values
        if (patternHash == textHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << i << " ";
        }

        // Calculate hash for next window
        if (i < n - m)
        {
            textHash = (base * (textHash - text[i] * h) + text[i + m]) % prime;
            if (textHash < 0)
                textHash += prime;
        }
    }

    cout << endl;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    rabinKarpSearch(s1, s2);

    return 0;
}