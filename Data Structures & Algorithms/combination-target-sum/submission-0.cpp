class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums,vector<int>& curr,int target,int idx){
        if(target==0){
            result.push_back(curr);
        }
        for(int i=idx;i<nums.size();i++){
            if(target<nums[i]) continue;
            curr.push_back(nums[i]);
            solve(nums,curr,target-nums[i],i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        solve(nums,curr,target,0);
        return result;
    }
};
