class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int p:nums){
            mp[p]++;
        }
        for(auto& n:mp){
            if(n.second>1){
                return n.first;
            }
        }
        return -1;
    }
};
