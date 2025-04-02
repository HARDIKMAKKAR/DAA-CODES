#include<iostream>
#include<vector>
using namespace std;
int partition(int arr[] , int si ,int ei){
    int pivotEle = arr[si];
    int count = 0;
    for(int i = si ; i <= ei ; i++){
        if(pivotEle > arr[i]){
            count++;
        }
    }
    int pivotIdx = count + si;
    //place the pivot ele at its correct place
    swap(arr[si] , arr[pivotIdx]);
    int i = si;
    int j = ei;
    //collecting all smaller ele on left and all greater ele on right
    while(i < pivotIdx && j > pivotIdx){
        if(arr[i] < pivotEle) i++;
        if(arr[j] > pivotEle) j--;
        else if(arr[i] > pivotEle && arr[j] < pivotEle){
            swap(arr[i] , arr[j]);
            j--;
            i++;
        }
    }
    return pivotIdx;
}
void quickSort(int arr[] , int si , int ei){
    if(si >= ei) return;
    int pivotIdx = partition(arr,si,ei);
    quickSort(arr,si,pivotIdx-1);
    quickSort(arr,pivotIdx+1,ei);
}
int main(){
    //int arr[] = {5,1,8,2,7,6,3,4};
    //5 1 8 2 7 6 3 4
    //1 2 3 4 5 6 7 8
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr,0,n-1);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}