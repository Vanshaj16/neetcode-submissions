class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>>res;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=n-1;
            int k=i+1;
            while(k<j){
                int sum=nums[i]+nums[k]+nums[j];
                if(sum==0){
                    res.push_back({nums[i],nums[k],nums[j]});
                    k++;
                    j--;
                    while(k<j && nums[k]==nums[k-1]) k++;
                    while(k<j && nums[j]==nums[j+1]) j--;
                }else if(sum>0){
                    j--;
                }else{
                    k++;
                }
            }
        }
        return res;
    }
};
