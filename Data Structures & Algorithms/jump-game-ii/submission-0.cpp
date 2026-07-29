class Solution {
private:
    int dfs(vector<int>& nums,int idx,unordered_map<int,int>& mp){
        if(idx==nums.size()-1) return 0;
        if(mp.count(idx)) return mp[idx];
        if(nums[idx]==0) return 1e9;
        int res=1e9;
        int end = min((int)nums.size()-1,idx+nums[idx]);
        for(int i=idx+1;i<=end;i++){
            res=min(res,1+dfs(nums,i,mp));
        }
        return mp[idx]=res;
    }
public:
    int jump(vector<int>& nums) {
        unordered_map<int,int> mp;
        return dfs(nums,0,mp);
    }
};
