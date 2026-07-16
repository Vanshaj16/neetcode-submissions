class Solution {
public:
    vector<vector<int>> res;
    void backTrack(vector<int>& nums,vector<int>& cur,int n,int idx){
        if(idx>=n){
            return;
        }
        for(int i=idx;i<n;i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            cur.push_back(nums[i]);
            res.push_back(cur);
            backTrack(nums,cur,n,i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        res.push_back({});
        vector<int> cur;
        backTrack(nums,cur,n,0);
        return res;
    }
};
