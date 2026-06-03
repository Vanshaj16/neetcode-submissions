class Solution {
public:
    int solve(vector<int>& cost,int idx,vector<int>& dp){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int one = cost[idx]+solve(cost,idx+1,dp);
        int two = cost[idx]+solve(cost,idx+2,dp);
        return dp[idx]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        int res=min(solve(cost,0,dp),solve(cost,1,dp));
        return res;
    }
};