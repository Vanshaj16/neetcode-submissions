class Solution {
public: 
    int n=0;
    int result=0;
    int solve(vector<int>& nums,int target,int idx,int currSum,int totalSum,vector<vector<int>>& dp){
        if(idx==n){
            return (currSum==target)?1:0;
        }
        if(dp[idx][currSum+totalSum]!=-1){
            return dp[idx][currSum+totalSum];
        }
        int add = solve(nums,target,idx+1,currSum+nums[idx],totalSum,dp);
        int sub = solve(nums,target,idx+1,currSum-nums[idx],totalSum,dp);

        return dp[idx][currSum+totalSum] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        int totalSum=0;
        for(int num:nums){
            totalSum+=num;
        }
        if(abs(target)>totalSum) return 0;
        vector<vector<int>> dp(n,vector<int>(2*totalSum+1,-1));
        return solve(nums,target,0,0,totalSum,dp);
    }
};
