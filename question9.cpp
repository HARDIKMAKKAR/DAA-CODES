#include<iostream>
#include<vector>
using namespace std;
int findPeakElement(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int peakIndex = findPeakElement(nums);
    cout << "Index of peak element: " << peakIndex << endl;
    cout << "Peak element: " << nums[peakIndex] << endl;
    return 0;
}
