#include <bits/stdc++.h>
using namespace std;

// Job Scheduling (Greedy)
// Output: total profit + selected job IDs (in time order)
pair<int, vector<int>> jobSchedulingGreedy(const vector<int> &profit, const vector<int> &deadline)
{
    int n = profit.size();

    // Create list of jobs (profit, deadline, id)
    vector<tuple<int, int, int>> jobs;
    for (int i = 0; i < n; i++)
        jobs.push_back({profit[i], deadline[i], i + 1});

    // Sort by profit descending
    sort(jobs.begin(), jobs.end(),
         [](auto &a, auto &b)
         { return get<0>(a) > get<0>(b); });

    int maxDeadline = *max_element(deadline.begin(), deadline.end());
    int slotsCount = min(maxDeadline, n);
    vector<int> slots(slotsCount, 0); // 0 = empty

    int totalProfit = 0;

    for (auto &job : jobs)
    {
        int p = get<0>(job);
        int d = get<1>(job);
        int id = get<2>(job);

        // Place job at latest free slot before its deadline
        for (int s = min(d, slotsCount) - 1; s >= 0; s--)
        {
            if (slots[s] == 0)
            {
                slots[s] = id;
                totalProfit += p;
                break;
            }
        }
    }

    vector<int> selectedJobs;
    for (int id : slots)
        if (id != 0)
            selectedJobs.push_back(id);

    return {totalProfit, selectedJobs};
}

int main()
{
    vector<int> profit = {20, 15, 10, 5};
    vector<int> deadline = {2, 2, 1, 3};

    auto result = jobSchedulingGreedy(profit, deadline);
    int totalProfit = result.first;
    vector<int> jobIds = result.second;

    cout << "Job Scheduling:\n";
    cout << "Total Profit = " << totalProfit << "\nJobs Selected: ";
    for (int id : jobIds)
        cout << id << " ";
    cout << endl;

    return 0;
}