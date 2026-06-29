class Solution {
public:
    vector<vector<int>> res;
    void recursion(vector<int>& nums,vector<int>& cur,int idx,int n){
        if(idx>=n){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[idx]);
        recursion(nums,cur,idx+1,n);
        cur.pop_back();
        recursion(nums,cur,idx+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> cur;
        recursion(nums,cur,0,n);
        return res;
    }
};
