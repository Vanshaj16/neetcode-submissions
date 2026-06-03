class Solution {
public:
    int memoSolve(vector<int>& nums,int idx,vector<int>& dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take=nums[idx]+memoSolve(nums,idx+2,dp);
        int notTake=memoSolve(nums,idx+1,dp);
        return dp[idx]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return memoSolve(nums,0,dp);
    }
};
