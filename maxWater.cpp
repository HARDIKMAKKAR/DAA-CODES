#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxArea(vector<int>& height) {
    int l = 0;
    int h = height.size() - 1;
    int maxWater = INT_MIN;
    
    while (l < h) {
        int waterCount = min(height[l], height[h]) * (h - l);
        maxWater = max(waterCount, maxWater);
        if (height[l] <= height[h]) 
            l++;
        else 
            h--;
    }
    
    return maxWater;
}

int main() {
    vector<int> height = {1,4 , 2 ,3};
    cout << "Maximum water that can be stored: " << maxArea(height) << endl;
    return 0;
}
