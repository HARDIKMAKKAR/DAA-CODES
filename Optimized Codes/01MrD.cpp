
#include<bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int>& wt, vector<int>& profit, int n) {
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++) {
        for(int w=0;w<=W;w++) {
            if(wt[i-1] <= w) dp[i][w] = max(profit[i-1] + dp[i - 1][w-wt[i-1]], dp[i-1][w]);
            else dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W]; 
}
int main(){
    int n,m;
    cout<<"Enter capacity of bag: "<<endl;
    cin>>m;
    cout<<"Enter no. of objects: "<<endl;
    cin>>n;
    vector<int>wt(n), profit(n);
    cout<<"Enter weight of objects: "<<endl;
    for(int i=0;i<n;i++) cin>>wt[i];
    cout<<"Enter profit of objects: "<<endl;
    for(int i=0;i<n;i++) cin>>profit[i];
    cout << "Maximum value in Knapsack: " << knapsack(m, wt, profit, n) << endl;
}

