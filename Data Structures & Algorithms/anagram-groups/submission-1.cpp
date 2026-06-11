class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for(string& s:strs){
            string sRef=s;
            sort(begin(sRef),end(sRef));
            mp[sRef].push_back(s);
        }
        for(auto& it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};
