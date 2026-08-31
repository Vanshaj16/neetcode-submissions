class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int res=INT_MAX;
        int l=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>=target){
                res=min(res,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return res==INT_MAX?0:res;
    }
};