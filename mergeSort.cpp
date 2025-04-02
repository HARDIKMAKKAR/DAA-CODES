#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &a , vector<int> &b , vector<int> &c){
    int n1 = a.size();
    int n2 = b.size();
    int n3 = c.size();
    int i = 0 , j = 0 , k = 0;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
    if(i == n1){
        while(j < n2){
            c[k++] = b[j++];
        }
    }
    else{
        while(i < n1){
            c[k++] = a[i++];
        }
    }
}

void mergeSort(vector<int>&v){
    int n = v.size();
    if(n <= 1){
        return;
    }
    int n1 = n / 2;
    int n2 = n - n1;
    vector <int> a(n1);
    vector <int> b(n2);
    for(int i = 0 ; i < n1 ; i++){
        a[i] = v[i];
    }
    for(int i = 0 ; i < n2 ; i++){
        b[i] = v[i + n1];
    }
    mergeSort(a);
    mergeSort(b);
    merge(a, b, v);
}

int main(){
    vector<int> v1 = {5, 9, 2, 4, 6, 8, 9, 0};
    mergeSort(v1);
    for(int i = 0 ; i < v1.size() ; i++){
        cout << v1[i] << " ";
    }
}
