class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mp;
        for(char& c:s){
            mp[c]++;
        }
        for(char& k:t){
            if(mp.count(k)>0){
                mp[k]--;
            }else{
                return false;
            }
        }
        for(auto& i:mp){
            if(i.second>0){
                return false;
            }
        }
        return true;
    }
};
