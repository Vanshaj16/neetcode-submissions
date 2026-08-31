class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char,int> mp;
        for(char ch:t){
            mp[ch]++;
        }
        int need=mp.size();
        int start=0;
        int minL=INT_MAX;
        int l=0;
        for(int r=0;r<s.size();r++){
            if(mp.find(s[r])!=mp.end()){
                mp[s[r]]--;
                if(mp[s[r]]==0){
                    need--;
                }
            }
            while(need==0){
                if(r-l+1<minL){
                    start=l;
                    minL=r-l+1;
                }
                char left=s[l++];
                if(mp.count(left)){
                    if(mp[left]==0){
                        need++;
                    }
                    mp[left]++;
                }
            }
        }
        return minL==INT_MAX?"":s.substr(start,minL);
    }
};