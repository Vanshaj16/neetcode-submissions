class Solution {
public:
    int lps(string& s,vector<vector<int>>& dp,int i,int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int same=0,a=0,b=0,c=0;
        if(s[i]==s[j] && i<j){
            same=2+lps(s,dp,i+1,j-1);
        }else if(i<j){
            a=lps(s,dp,i,j-1);
            b=lps(s,dp,i+1,j);
            c=max(a,b);
        }
        return dp[i][j]=max(same,c);
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return lps(s,dp,0,n-1);
    }
};