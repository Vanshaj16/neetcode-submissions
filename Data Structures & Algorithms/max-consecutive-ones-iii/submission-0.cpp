class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int i=0,j=0;
        int res=0;
        while(j<n){
            if(nums[j]==0) count++;
            while(count>k){
                if(nums[i]==0){
                    count--;
                }
                i++;
            }
            if(count<=k){
                res=max(res,j-i+1);
            }
            j++;
        }
        return res;
    }
};