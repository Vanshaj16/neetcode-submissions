class Solution {
public:
//Memoization
    bool palindromicS(string& s,int i,int j,vector<vector<int>>& dp){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]=palindromicS(s,i+1,j-1,dp);
        }
        
        return dp[i][j]=false;
    }
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int cnt=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(palindromicS(s,i,j,dp)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
