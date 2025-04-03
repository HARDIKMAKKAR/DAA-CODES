#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int w;
    cout << "Enter the weight capacity of the knapsack: ";
    cin >> w;

    vector<pair<int, int>> v(n);
    cout << "Enter the value and weight of each item:\n";

    for (int i = 0; i < n; i++) {
        cout << "Value and weight of item " << i + 1 << ": ";
        cin >> v[i].first >> v[i].second;
    }

    // Sorting items based on value-to-weight ratio in descending order
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });

    double maxValue = 0;

    for (int i = 0; i < n; i++) {
        if (v[i].second <= w) {
            maxValue += v[i].first;
            w -= v[i].second;
        } else {
            maxValue += (double)v[i].first / v[i].second * w;
            break;
        }
    }

    cout << "Maximum value that can be obtained: " << maxValue << endl;
}
