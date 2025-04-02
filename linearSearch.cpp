#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter Size of Array !!";
    cin >> n;
    int arr[n];
    cout << "Enter Elements of Array !!";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int target;
    cout << "Enter Target Element you want to search !!";
    cin >> target;
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"Target found at index "<<i<<endl;
            flag=1;
        }
    }
    if(flag==0) cout<<"Target not found";
    return 0;
}
