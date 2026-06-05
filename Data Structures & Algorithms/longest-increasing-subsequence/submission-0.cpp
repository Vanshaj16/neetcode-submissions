class Solution {
public:
    int lis(vector<int>& nums,vector<vector<int>>& dp,int prev,int idx){
        if(idx==nums.size()) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int take=0;
        if(prev==-1 || nums[prev]<nums[idx]){
            take=1+lis(nums,dp,idx,idx+1);
        }
        int notTake=lis(nums,dp,prev,idx+1);
        return dp[idx][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return lis(nums,dp,-1,0);
    }
};
