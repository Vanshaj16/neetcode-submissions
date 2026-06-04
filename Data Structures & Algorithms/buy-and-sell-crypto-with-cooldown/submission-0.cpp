class Solution {
public:
    int func(vector<int>& prices,int idx,int k,vector<vector<int>>& dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int profit=0;
        if(k==0){
            int buy=-prices[idx]+func(prices,idx+1,1,dp);
            int notBuy=func(prices,idx+1,0,dp);
            profit=max(buy,notBuy);
        }else{
            int sell=prices[idx]+func(prices,idx+2,0,dp);
            int notSell=func(prices,idx+1,1,dp);
            profit=max(sell,notSell);
        }
        return dp[idx][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return func(prices,0,0,dp);
    }
};
