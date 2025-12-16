#include <bits/stdc++.h>
using namespace std;

// Iterative approach
double powerIterative(double base, int exponent)
{
    double result = 1;

    if (exponent >= 0)
    {
        for (int i = 0; i < exponent; i++)
            result *= base;
    }
    else
    {
        for (int i = 0; i < -exponent; i++)
            result *= base;
        result = 1 / result;
    }
    return result;
}

// Recursive approach
double powerRecursive(double base, int exponent)
{
    if (exponent == 0)
        return 1;

    if (exponent < 0)
        return 1 / powerRecursive(base, -exponent);

    return base * powerRecursive(base, exponent - 1);
}

int main()
{
    double base;
    int exponent;

    cout << "Enter number: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exponent;

    cout << "Result using iterative method: "
         << powerIterative(base, exponent) << endl;

    cout << "Result using recursive method: "
         << powerRecursive(base, exponent) << endl;

    return 0;
}