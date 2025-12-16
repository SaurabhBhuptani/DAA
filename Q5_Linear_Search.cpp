#include <bits/stdc++.h>
using namespace std;

bool LinearSearch(const vector<int> &numbers, int target)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == target)
            return true; // early exit (optimal)
    }
    return false;
}

void readArray(vector<int> &numbers)
{
    cout << "Enter array elements: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cin >> numbers[i];
    }
}

void displayArray(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main()
{
    int elementCount, target;
    cout << "Enter size of array: ";
    cin >> elementCount;

    vector<int> numbers(elementCount);
    readArray(numbers);

    cout << "Array: ";
    displayArray(numbers);

    cout << "Element to be found: ";
    cin >> target;

    bool found = LinearSearch(numbers, target);
    cout << found;

    return 0;
}