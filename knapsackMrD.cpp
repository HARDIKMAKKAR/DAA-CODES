#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    double r1 = (double)a.first/a.second;
    double r2 = (double)b.first/b.second;
    return r1>r2;
}
int main(){
    int n;
    cout<<"Enter the no. of items : ";
    cin>>n;
    int w;
    cout<<"Enter the weight of the knapsack : ";
    cin>>w;
    vector<pair<int,int>> v(n);
    cout<<"Enter the value and weight of the items!\n";
    for(int i=0;i<n;i++){
        cout<<"Enter the value and weight of item "<<i+1<<" : ";
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    double ans = 0;
    for(int i=0 ; i<n ; i++){
        if(v[i].second<=w){
            ans += v[i].first;
            w -= v[i].second;
        }
        else{
            ans = ans + ((double)v[i].first/v[i].second)*w;
            break;
        }
    }
    cout<<"Maximum value that can be obtained : "<<ans<<endl;
}

