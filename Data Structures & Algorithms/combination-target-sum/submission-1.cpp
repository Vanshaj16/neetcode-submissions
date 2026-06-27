class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums,vector<int>& curr,int target,int idx){
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(target<0 || idx>=nums.size()){
            return;
        }
        curr.push_back(nums[idx]);
        solve(nums,curr,target-nums[idx],idx);
        curr.pop_back();
        solve(nums,curr,target,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        solve(nums,curr,target,0);
        return result;
    }
};
