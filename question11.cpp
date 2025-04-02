#include<iostream>
#include<vector>
using namespace std;

int findKthPositive(const vector<int>& arr, int k) {
    int left = 0;
    int right = arr.size();
    // Perform binary search to find the kth missing positive number
    while (left < right) {
        int mid = left + (right - left) / 2;
        // Calculate the number of missing numbers before arr[mid]
        if (arr[mid] - (mid + 1) < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left + k;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = findKthPositive(arr, k);
    cout << "The " << k << "th missing positive number is: " << result << endl;

    return 0;
}
