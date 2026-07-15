class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums,int target,vector<int>& curr,int idx){
        if(target==0){
            res.push_back(curr);
            return;
        }
        for(int j=idx;j<nums.size();j++){
            if(target-nums[j]<0) break;
            curr.push_back(nums[j]);
            dfs(nums,target-nums[j],curr,j);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        dfs(nums,target,curr,0);
        return res;
    }
};
