class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> hashSet;
        for(int& p:nums){
            if(hashSet.count(p)>0){
                return true;
            }
            hashSet.insert(p);
        }
        return false;
    }
};