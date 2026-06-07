class Solution {
public:
//Bottom Up Approach
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n+1,false));
        int cnt=0;
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j){
                    dp[i][i]=true;
                }else if(i+1==j){
                    if(s[i]==s[j]) dp[i][j]=true;
                }else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
