class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> maxH;
        for(auto& a:mp){
            maxH.push({a.second,a.first});
        }
        vector<int> result;
        while(k--){
            result.push_back(maxH.top().second);
            maxH.pop();
        }
        return result;
    }
};
