class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int count=0;
        for(int& a:nums){
            if(a==1){
                count++;
                res=max(count,res);
            }else count=0;
        }
        return res;
    }
};