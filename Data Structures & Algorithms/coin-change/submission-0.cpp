class Solution {
public:
    int change(vector<int>& coins,int amount,int idx,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(idx<0) return 1e9;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notTake=change(coins,amount,idx-1,dp);
        int take=1e9;
        if(amount>=coins[idx]){
            take=1+change(coins,amount-coins[idx],idx,dp);
        }
        return dp[idx][amount]=min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = change(coins,amount,n-1,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};