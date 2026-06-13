class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int num:nums) mp[num]++;
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            mp[nums[i]]--;
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                mp[nums[j]]--;
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int target=-(nums[i]+nums[j]);
                if(mp[target]>0){
                    result.push_back({nums[i],nums[j],target});
                }
            }
            for(int j=i+1;j<n;j++){
                mp[nums[j]]++;
            }
        }
        return result;
    }
};
