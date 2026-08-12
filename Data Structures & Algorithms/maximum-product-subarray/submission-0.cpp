class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[0];
        int result=nums[0];
        for(int i=1;i<n;i++){
            int curr=nums[i];
            int temp_max=max({curr,maxi*curr,mini*curr});
            mini=min({curr,maxi*curr,mini*curr});

            maxi=temp_max;
            result=max(result,maxi);
        }
        return result;
    }
};
