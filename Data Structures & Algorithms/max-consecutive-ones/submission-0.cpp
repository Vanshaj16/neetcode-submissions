class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int count=0;
        int res=0;
        while(r<n){
            if(nums[r]==1){
                count++;
                res=max(res,count);
            }else count=0;
            r++;
        }
        return res>count?res:count;
    }
};