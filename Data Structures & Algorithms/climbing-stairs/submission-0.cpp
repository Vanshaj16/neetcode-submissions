class Solution {
public:
    int solve(int idx,vector<int>& dp){
        if(idx<=1) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int one=solve(idx-1,dp);
        int two=solve(idx-2,dp);
        return dp[idx]=one+two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int res=solve(n,dp);
        return res;
    }
};
