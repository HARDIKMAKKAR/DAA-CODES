class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<int>dp(W+1,0);
        
        for(int i = 0 ; i < val.size() ; i++){
            for(int j = W ; j>= wt[i] ; j--){
                dp[j] = max(dp[j] , val[i]+dp[j-wt[i]]);
            }
        }
        
        return dp[W];
    }
};