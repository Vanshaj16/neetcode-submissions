class Solution {
public:
    bool check(string& s,unordered_set<string>& st,int n,int idx,vector<int>& dp){
        if(idx==n){
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        if(st.find(s)!=st.end()) return true;

        for(int l=1;l<=n;l++){
            string t=s.substr(idx,l);
            if(st.find(t)!=st.end() && check(s,st,n,idx+l,dp)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(n,-1);
        return check(s,st,n,0,dp);
    }
};
