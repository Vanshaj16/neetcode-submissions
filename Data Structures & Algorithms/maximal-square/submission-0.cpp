class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(matrix.empty()) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || matrix[i][j]=='0'){
                    dp[i][j]=matrix[i][j]-'0';
                }else{
                    dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                }
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi*maxi;
    }
};