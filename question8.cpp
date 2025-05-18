#include<iostream>
#include<vector>
using namespace std;
int findfirst(vector<int>& nums, int target) {
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
int findLast(vector<int>& nums, int target) {
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
int count(vector<int>& nums, int target) {
    int first = findfirst(nums, target);
    if (first == -1) return 0;
    int last = findLast(nums, target);
    return last - first + 1;
}
int main() {
    vector<int> nums = {5,4,4,4,6,7,8,9};
    int target = 4;
    cout << "Number of occurrences of " << target << " is: " << count(nums, target) << endl;
    return 0;
}
   