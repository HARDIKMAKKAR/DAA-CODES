#include <iostream>
#include <vector>

using namespace std;

int activitySelectionBruteForce(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isSelected = true;
        for (int j = 0; j < i; j++) {
            if (start[i] < finish[j] && start[j] < finish[i]) {
                isSelected = false;
                break;
            }
        }
        if (isSelected) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> start1 = {10, 12, 20};
    vector<int> finish1 = {20, 25, 30};

    vector<int> start2 = {1, 3, 0, 5, 8, 5};
    vector<int> finish2 = {2, 4, 6, 7, 9, 9};  

    cout << "Maximum number of activities " << activitySelectionBruteForce(start1, finish1) << endl;
    cout << "Maximum number of activities " << activitySelectionBruteForce(start2, finish2) << endl;

    return 0;
}
