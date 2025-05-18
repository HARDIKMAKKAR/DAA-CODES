#include<iostream>
using namespace std;
int main() {
    int n=7;
    int arr[n]={5,4,1,2,3,4,0};
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
