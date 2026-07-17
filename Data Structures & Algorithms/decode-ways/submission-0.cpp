class Solution {
public:
    int decode(string& s,int n,int idx,vector<int>& dp){
        if(idx>=n) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int ways=0;
        if(s[idx]!='0'){
            ways=decode(s,n,idx+1,dp);
        }
        if(idx<n-1 && (s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6'))){
            ways+=decode(s,n,idx+2,dp);
        }
        dp[idx]=ways;
        return ways;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return decode(s,n,0,dp);
    }
};
