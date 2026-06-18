class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int res=0;
        unordered_map<char,int> mp;
        for(int j=0;j<n;j++){
            while(i<j && mp.find(s[j])!=mp.end()){
                mp.erase(s[i]);
                i++;
            }
            mp[s[j]]++;
            res=max(res,j-i+1);
        }
        return res;
    }
};