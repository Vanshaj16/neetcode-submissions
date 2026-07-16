class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> st;
    void backTrack(vector<int>& nums,vector<int>& cur,int n,int idx){
        if(idx>=n){
            st.insert(cur);
            return;
        }
        cur.push_back(nums[idx]);
        backTrack(nums,cur,n,idx+1);
        cur.pop_back();
        backTrack(nums,cur,n,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> cur;
        backTrack(nums,cur,n,0);
        for(auto& it:st){
            res.push_back(it);
        }
        return res;
    }
};
