class Solution {
private:
    bool solve(vector<int>& nums,int idx,int target,vector<vector<int>>& dp){
        if(target==0) return true;
        if(idx==nums.size()-1 || target<0) return false;

        if(dp[idx][target]!=-1) return dp[idx][target];
        bool take=solve(nums,idx+1,target-nums[idx],dp);
        bool notTake=solve(nums,idx+1,target,dp);
        return dp[idx][target]=(take||notTake);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        int n=nums.size();
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(nums,0,sum/2,dp);
    }
};
