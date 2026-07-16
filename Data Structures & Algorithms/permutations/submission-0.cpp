class Solution {
public:
    vector<vector<int>> res;
    void backTrack(vector<int>& nums,vector<int>& curr,vector<bool>& used,int n){
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(!used[i]){
                used[i]=true;
                curr.push_back(nums[i]);
                backTrack(nums,curr,used,n);
                curr.pop_back();
                used[i]=false;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> curr;
        vector<bool> used(n,false);
        backTrack(nums,curr,used,n);
        return res;
    }
};
