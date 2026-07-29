class Solution {
public:
    int dfs(vector<int>& prices,int k,int idx,vector<vector<int>>& dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int profit=0;
        if(k==0){
            int buy= -prices[idx]+dfs(prices,1,idx+1,dp);
            int notBuy=dfs(prices,0,idx+1,dp);
            profit=max(buy,notBuy);
        }else{
            int sell=prices[idx]+dfs(prices,0,idx+1,dp);
            int notSell=dfs(prices,1,idx+1,dp);
            profit=max(sell,notSell);
        }
        return dp[idx][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return dfs(prices,0,0,dp);
    }
};