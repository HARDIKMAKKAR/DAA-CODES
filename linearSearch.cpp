#include<iostream>
using namespace std;
int main(){
    int n=8;
    int arr[n]={1,2,3,4,5,6,7,8};
    int target=2;
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
