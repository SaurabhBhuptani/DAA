#include <bits/stdc++.h>
using namespace std;

vector<int> CountingSort(const vector<int> &numbers)
{
    int size = numbers.size();

    // Find maximum element
    int maxValue = 0;
    for (int i = 0; i < size; i++)
        maxValue = max(maxValue, numbers[i]);

    // Frequency array
    vector<int> count(maxValue + 1, 0);
    for (int i = 0; i < size; i++)
        count[numbers[i]]++;

    // Cumulative count
    for (int i = 1; i <= maxValue; i++)
        count[i] += count[i - 1];

    // Output array (stable)
    vector<int> sortedNumbers(size);
    for (int i = size - 1; i >= 0; i--)
    {
        sortedNumbers[count[numbers[i]] - 1] = numbers[i];
        count[numbers[i]]--;
    }

    return sortedNumbers;
}

void readArray(vector<int> &numbers)
{
    cout << "Enter elements: ";
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
    int elementCount;
    cout << "Enter number of elements: ";
    cin >> elementCount;

    vector<int> numbers(elementCount);
    readArray(numbers);

    vector<int> sortedNumbers = CountingSort(numbers);
    displayArray(sortedNumbers);

    return 0;
}