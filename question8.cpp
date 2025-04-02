#include<iostream>
#include<vector>
using namespace std;
int findFirstOccurrence(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}
int findLastOccurrence(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}
int countOccurrences(const vector<int>& nums, int target) {
    int first = findFirstOccurrence(nums, target);
    if (first == -1) return 0;
    int last = findLastOccurrence(nums, target);
    return last - first + 1;
}
int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;
    cout << "Number of occurrences of " << target << " is: " << countOccurrences(nums, target) << endl;
    return 0;
}
