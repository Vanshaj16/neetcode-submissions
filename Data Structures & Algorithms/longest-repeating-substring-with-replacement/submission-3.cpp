class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int res=0, maxFreq=0;
        unordered_map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            maxFreq=max(maxFreq,mp[s[r]]);
            while(l<r && (r-l+1)-maxFreq>k){
                mp[s[l]]--;
                l++;
            }
            if((r-l+1)-maxFreq<=k){
                res=max(res,r-l+1);
            }
            r++;
        }
        return res;
    }
};
