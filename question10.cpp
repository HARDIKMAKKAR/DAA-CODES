#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>& arr, int si, int ei) {
    int pivotEle = arr[si];
    int count = 0;
    for (int i = si; i <= ei; i++) {
        if (pivotEle > arr[i]) {
            count++;
        }
    }
    int pivotIdx = count + si;
    swap(arr[si], arr[pivotIdx]);
    int i = si;
    int j = ei;
    while (i < pivotIdx && j > pivotIdx) {
        if (arr[i] < pivotEle) i++;
        if (arr[j] > pivotEle) j--;
        else if (arr[i] > pivotEle && arr[j] < pivotEle) {
            swap(arr[i], arr[j]);
            j--;
            i++;
        }
    }
    return pivotIdx;
}
int quickSelect(vector<int>& arr, int si, int ei, int k) {
    if (si <= ei) {
        int pivotIdx = partition(arr, si, ei);
        if (pivotIdx == k) {
            return arr[pivotIdx];
        } else if (pivotIdx > k) {
            return quickSelect(arr, si, pivotIdx - 1, k);
        } else {
            return quickSelect(arr, pivotIdx + 1, ei, k);
        }
    }
    return -1;
}
int main() {
    int n, k;
    cout << "Enter the size of your array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements of your array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "enter k";
    cin >> k;
    int targetIndex = n - k;
    int result = quickSelect(arr, 0, n - 1, targetIndex);
    cout << "The " << k << "th largest element in the array is: " << result << endl;
    return 0;
}
