#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Job structure to hold job details
struct Job {
    char id;        // Job ID
    int deadline;   // Deadline of job
    int profit;     // Profit of job
};

void jobSequencing(vector<Job>& jobs) {
    int n = jobs.size();

    // Sort jobs based on profit in descending order using lambda function
    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    // To keep track of free time slots
    vector<bool> slot(n, false);
    // To store the result (scheduled jobs)
    vector<char> result(n, '-');

    int totalProfit = 0;

    // Assign jobs to slots
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the latest possible slot)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                slot[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Display the scheduled jobs and total profit
    cout << "Scheduled Jobs: ";
    for (char job : result) {
        if (job != '-') cout << job << " ";
    }
    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    jobSequencing(jobs);

    return 0;
}
