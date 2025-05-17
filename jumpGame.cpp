#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;
    if (nums[0] == 0) return false;
    
    vector<bool> dp(nums.size(), false);
    dp[0] = true;
    
    for (int i = 0; i < nums.size(); i++) {
        if (!dp[i]) return false;
        int ele = nums[i];
        for (int j = 1; j <= ele; j++) {
            if (i + j == nums.size() - 1) return true;
            dp[i + j] = true;
        }
    }
    
    return dp[nums.size() - 1];
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    if (canJump(nums)) 
        cout << "Can reach the last index" << endl;
    else 
        cout << "Cannot reach the last index" << endl;
    
    return 0;
}
