#include <bits/stdc++.h>
using namespace std;

// Selection Sort
void SelectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;

        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        // Swap only if a smaller element is found
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}

// Function to read array elements
void readArray(vector<int> &arr)
{
    cout << "Enter elements: ";
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
}

// Function to display array elements
void displayArray(const vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    readArray(arr);
    SelectionSort(arr);
    displayArray(arr);

    return 0;
}