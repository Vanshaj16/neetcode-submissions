class Solution {
public:
    int partitionDp(int left,int right,vector<int>& nums,vector<vector<int>>& dp){
        if(left+1==right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int ans=0;
        for(int i=left+1;i<right;i++){
            int coins = nums[left]*nums[i]*nums[right] + partitionDp(left,i,nums,dp)
            +partitionDp(i,right,nums,dp);
            ans=max(ans,coins);
        }
        return dp[left][right]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return partitionDp(0,n+1,nums,dp);
    }
};
