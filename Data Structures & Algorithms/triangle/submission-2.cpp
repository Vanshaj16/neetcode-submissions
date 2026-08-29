class Solution {
public:
    int recursion(vector<vector<int>>& triangle,int r,int c,vector<vector<int>>& dp){
        if(r>=triangle.size()){
            return 0;
        }
        if(dp[r][c]!=INT_MAX) return dp[r][c];
        return dp[r][c] = triangle[r][c]+min(recursion(triangle,r+1,c,dp),recursion(triangle,r+1,c+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n, vector<int>(0));
        int INF = INT_MAX;
        for (int r=0;r<n;r++) {
            dp[r].resize(triangle[r].size(), INF);
        }
        return recursion(triangle,0,0,dp);
    }
};