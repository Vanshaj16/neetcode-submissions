class Solution {
public:
    bool dp(vector<int>& nums,int idx,unordered_map<int,bool>& mp){
        if(idx==nums.size()-1) return true;
        if(mp.count(idx)) return mp[idx];

        int r=min((int)nums.size()-1,idx+nums[idx]);
        for(int i=idx+1;i<=r;i++){
            if(dp(nums,i,mp)){
                return mp[idx] = true;
            }
        }
        return mp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        unordered_map<int,bool> mp;
        return dp(nums,0,mp);
    }
};
