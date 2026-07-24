class Solution {
public:
    bool recursion(string s,string t,int i,int j,vector<vector<int>>& dp){
        if(i==s.size()){
            return true;
        }
        if(j==t.size()){
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j]==1;
        if(s[i]==t[j]){
            dp[i][j]=recursion(s,t,i+1,j+1,dp)?1:0;
        }else{
            dp[i][j]=recursion(s,t,i,j+1,dp)?1:0;
        }
        return dp[i][j]==1;
    }
    bool isSubsequence(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recursion(s,t,0,0,dp);
    }
};