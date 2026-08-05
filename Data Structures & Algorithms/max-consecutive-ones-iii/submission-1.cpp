class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int cnt=0;
        if(n==0) return 0;
        int maxL=0;
        while(j<n){
            if(nums[j]==0){
                cnt++;
            }
            while(cnt>k){
                if(nums[i]==0){
                    cnt--;
                }
                i++;
            }
            maxL=max(maxL,j-i+1);
            j++;
        }
        return maxL;
    }
};