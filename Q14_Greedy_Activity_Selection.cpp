#include <bits/stdc++.h>
using namespace std;

// Activity Selection (Greedy)
// Output: selected activity IDs
vector<int> activitySelectionGreedy(const vector<int> &start, const vector<int> &finish)
{
    int n = start.size();

    vector<tuple<int, int, int>> activities;
    for (int i = 0; i < n; i++)
        activities.push_back({start[i], finish[i], i + 1});

    // Sort by finishing time ascending
    sort(activities.begin(), activities.end(),
         [](auto &a, auto &b)
         { return get<1>(a) < get<1>(b); });

    vector<int> selected;
    int lastFinish = -1;

    for (auto &act : activities)
    {
        int s = get<0>(act);
        int f = get<1>(act);
        int id = get<2>(act);

        if (s >= lastFinish)
        {
            selected.push_back(id);
            lastFinish = f;
        }
    }

    return selected;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8};
    vector<int> finish = {2, 4, 6, 7, 9};

    vector<int> selectedActivities = activitySelectionGreedy(start, finish);

    cout << "Activity Selection:\nSelected Activities: ";
    for (int id : selectedActivities)
        cout << id << " ";
    cout << endl;

    return 0;
}