class Solution {
public:
    int combination(vector<int>& nums,int total,unordered_map<int,int>& dp){
        if(total==0){
            return 1;
        }
        if(dp.count(total)) return dp[total];
        int res=0;
        for(int num:nums){
            if(total<num) break;
            res+=combination(nums,total-num,dp);
        }
        dp[total]=res;
        return res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> dp;
        return combination(nums,target,dp);
    }
};