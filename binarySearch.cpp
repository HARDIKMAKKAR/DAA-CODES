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
    int n=8;
    int arr[n]={1,2,3,4,5,6,7,8};
    int target=7;
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }
    return 0;
}
