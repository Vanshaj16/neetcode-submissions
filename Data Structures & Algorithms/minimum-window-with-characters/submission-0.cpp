class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size(), n2=t.size();
        if(n1<n2) return "";
        string res="";
        unordered_map<char,int> mp;
        for(char p:t){
            mp[p]++;
        }
        int need=mp.size();
        int l=0;
        int start=0;
        int minLen=INT_MAX;
        for(int r=0;r<n1;r++){
            if(mp.count(s[r])){
                mp[s[r]]--;
                if(mp[s[r]]==0){
                    need--;
                }
            }
            while(need==0){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                int left=s[l++];
                if(mp.count(left)){
                    if(mp[left]==0) need++;
                    mp[left]++;
                }
            }
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};
