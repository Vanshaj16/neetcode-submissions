class Solution {
public:
    int lcs(string& text1,string& text2,int idx1,int idx2,vector<vector<int>>& dp){
        if(idx1==text1.size() || idx2==text2.size()){
            return 0;
        }
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int take=0,a=0,b=0,c=0;
        if(text1[idx1]==text2[idx2]){
            take=1+lcs(text1,text2,idx1+1,idx2+1,dp);
        }else{
            a=lcs(text1,text2,idx1,idx2+1,dp);
            b=lcs(text1,text2,idx1+1,idx2,dp);
            c=max(a,b);
        }
        return dp[idx1][idx2]=max(take,c);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length();
        int l2=text2.length();
        vector<vector<int>> dp(l1,vector<int>(l2,-1));
        return lcs(text1,text2,0,0,dp);
    }
};