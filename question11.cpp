#include<iostream>
#include<vector>
using namespace std;

int findKthPositive(const vector<int>& arr, int k) {
    int size=arr.size();
    int curr=1;
    int miss=0;
    for(int i=0;i<size;i++){
        while(curr<arr[i]){
            miss++;
            if(miss==k){
                return curr;
            }
            curr++;
        }
        curr=arr[i]+1;
    }
    while (miss < k) {
    miss++;
    if (miss == k) {
        return curr; 
    }
    curr++;
    }
    return -1;
}

int main() {
    int n=5, k=2;
    vector<int> arr={1,4,7,9,12};
    int result = findKthPositive(arr, k);
    cout << "The " << k << " missing positive number is: " << result << endl;

    return 0;
}
