#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;
    int arr[n];
    cout << "Enter Elements of Array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
