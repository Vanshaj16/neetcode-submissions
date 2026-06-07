class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n+1,false));
        int start=0,maxL=INT_MIN;
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j){
                    dp[i][i]=true;
                }else if(i+1==j){
                    if(s[i]==s[j]) dp[i][j]=true;
                }else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]==true);
                }
                if(dp[i][j]==true){
                    start=i;
                    maxL=j-i+1;
                }
            }
        }
        return s.substr(start, maxL);
    }
};