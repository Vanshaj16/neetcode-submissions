class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(); // Tabulation
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){ // Initializing the last row of dp with triangle last row
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){ // The column size as per the row index
                int left=triangle[i][j]+dp[i+1][j];
                int right=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(left,right);
            }
        }
        return dp[0][0];
    }
};
