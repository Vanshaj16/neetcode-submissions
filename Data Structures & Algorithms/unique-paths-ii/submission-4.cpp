class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<int> dp(n,0); // Initializing all dp position with 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[j]=0;
                }else if(i==0 && j==0){
                    dp[j]=1; // Starting with 1 at (0,0)
                }else{
                    int up=dp[j];
                    int left=(j>0)?dp[j-1]:0;
                    dp[j]=up+left;
                }
            }
        }
        return dp[n-1];
    }
};