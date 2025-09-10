#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), cmp);
    int n = jobs.size();
    int max_deadline = 0;
    for (auto& job : jobs) max_deadline = max(max_deadline, job.deadline);
    vector<int> slot(max_deadline + 1, -1);
    int total_profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }
    cout << "Scheduled jobs: ";
    for (int j = 1; j <= max_deadline; j++) {
        if (slot[j] != -1) cout << jobs[slot[j]].id << " ";
    }
    cout << endl;
    return total_profit;
}

int main() {
    vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };
    int max_profit = jobSequencing(jobs);
    cout << "Maximum Profit: " << max_profit << endl;
    return 0;
}
