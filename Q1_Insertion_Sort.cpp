#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &numbers)
{
    int size = numbers.size();

    for (int i = 1; i < size; i++)
    {
        int key = numbers[i]; // element to be placed
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }
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
    InsertionSort(numbers);
    displayArray(numbers);

    return 0;
}