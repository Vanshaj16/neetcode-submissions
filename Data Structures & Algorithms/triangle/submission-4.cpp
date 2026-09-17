class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(); // Space Optimization
        vector<int> dp(n,0);
        vector<int> cur(n,0);
        for(int i=0;i<n;i++){ // Initializing the last row of dp with triangle last row
            dp[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){ // The column size as per the row index
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};
