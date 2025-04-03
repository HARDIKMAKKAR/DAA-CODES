#include <iostream>
using namespace std;

int partitionIndex(int arr[], int low, int high) {
    int pivot = low;
    int l = low + 1;
    int h = high;

    while (l <= h) {
        while (l <= high && arr[l] <= arr[pivot]) {
            l++;
        }
        while (arr[h] > arr[pivot]) {
            h--;
        }
        if (l < h) {
            int temp = arr[l];
            arr[l] = arr[h];
            arr[h] = temp;
        }
    }
    int temp = arr[h];
    arr[h] = arr[pivot];
    arr[pivot] = temp;

    return h;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionIndex(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[10], n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
