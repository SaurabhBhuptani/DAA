#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &numbers, int left, int mid, int right)
{
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (numbers[i] < numbers[j])
        {
            temp.push_back(numbers[i]);
            i++;
        }
        else
        {
            temp.push_back(numbers[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(numbers[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(numbers[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++)
    {
        numbers[left + k] = temp[k];
    }
}

void MergeSort(vector<int> &numbers, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSortOptimal(numbers, left, mid);
    mergeSortOptimal(numbers, mid + 1, right);
    mergeArrays(numbers, left, mid, right);
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
    cout << "Enter size of array: ";
    cin >> elementCount;

    vector<int> numbers(elementCount);
    readArray(numbers);

    MergeSort(numbers, 0, elementCount - 1);

    displayArray(numbers);
    return 0;
}