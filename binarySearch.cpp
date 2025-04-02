#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1; 
        }
    }
    return -1;
}
int main() {
    int n;
    cout << "Enter Size of Array !!";
    cin >> n;
    int arr[n];
    cout << "Enter Elements of Array (sorted) !!";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cout << "Enter Target Element you want to search !!";
    cin >> target;
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }
    return 0;
}
