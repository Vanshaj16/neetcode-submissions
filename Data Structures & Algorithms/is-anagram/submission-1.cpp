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
                if(mp[k]==0) mp.erase(k);
            }else{
                return false;
            }
        }
        return mp.size()==0?true:false;
    }
};
