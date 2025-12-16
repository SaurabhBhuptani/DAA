#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }

        // If no swaps occurred, array is already sorted
        if (!isSwapped)
            break;
    }
}

void inputArray(vector<int> &arr)
{
    cout << "Enter array elements: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void printArray(const vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    inputArray(arr);
    BubbleSort(arr);
    printArray(arr);

    return 0;
}