#include <bits/stdc++.h>
using namespace std;

int BinarySearch(const vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (numbers[mid] == target)
            return mid;
        else if (numbers[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
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
    int elementCount;
    cout << "Enter the size: ";
    cin >> elementCount;

    vector<int> numbers(elementCount);
    readArray(numbers);

    // Binary search requires sorted array
    sort(numbers.begin(), numbers.end());

    cout << "Sorted array: ";
    displayArray(numbers);

    int target;
    cout << "Element to be found: ";
    cin >> target;

    int index = BinarySearch(numbers, target);
    cout << "The element is found at index: " << index;

    return 0;
}