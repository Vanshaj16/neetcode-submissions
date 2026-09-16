class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(); //Tabulation
        int n=grid[0].size();
        vector<int> dp(n,0); // Store one row i.e prev one
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[j]=grid[0][0];
                    continue;
                }else{
                    int up=1e9, left=1e9; // Initialize with maximum
                    if(i>0) up=dp[j];
                    if(j>0) left=dp[j-1];
                    dp[j]=grid[i][j]+min(up,left);
                }
            }
        }
        return dp[n-1];
    }
};