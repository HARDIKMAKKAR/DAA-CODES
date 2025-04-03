#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakElement(vector<int>& arr, int l, int h, int size, int& maxIdx) {
        if (l > h) {
            return -1; 
        }
        int mid = l + (h - l) / 2;
        if (arr[mid] > arr[maxIdx]) {
            maxIdx = mid;
        }
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && 
            (mid == size - 1 || arr[mid + 1] <= arr[mid])) {
            return mid; 
        }
        int leftResult = peakElement(arr, l, mid - 1, size, maxIdx);
        if (leftResult != -1) {
            return leftResult; 
        }
        int rightResult = peakElement(arr, mid + 1, h, size, maxIdx);
        if (rightResult != -1) {
            return rightResult; 
        }
        return -1;
    }

    int findPeakElement(vector<int>& nums) {
        int h = nums.size() - 1;
        int l = 0;
        int maxIdx = 0; 
        int peakIdx = peakElement(nums, l, h, nums.size(), maxIdx);
        return peakIdx;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int peakIdx = solution.findPeakElement(nums);
    if (peakIdx != -1) {
        cout << "The peak element is " << nums[peakIdx] << " at index " << peakIdx << endl;
    } else {
        cout << "No peak element found." << endl;
    }
}
