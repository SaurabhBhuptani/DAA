#include <bits/stdc++.h>
using namespace std;

int partitionArray(vector<int> &numbers, int left, int right)
{
    int pivot = numbers[right];
    int partitionIndex = left - 1;

    for (int i = left; i < right; i++)
    {
        if (numbers[i] <= pivot)
        {
            partitionIndex++;
            swap(numbers[i], numbers[partitionIndex]);
        }
    }

    partitionIndex++;
    swap(numbers[partitionIndex], numbers[right]);
    return partitionIndex;
}

void QuickSort(vector<int> &numbers, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partitionArray(numbers, left, right);

        quickSortOptimal(numbers, left, pivotIndex - 1);
        quickSortOptimal(numbers, pivotIndex + 1, right);
    }
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
    cout << "Enter the size of array: ";
    cin >> elementCount;

    vector<int> numbers(elementCount);
    readArray(numbers);

    QuickSort(numbers, 0, elementCount - 1);

    displayArray(numbers);
    return 0;
}