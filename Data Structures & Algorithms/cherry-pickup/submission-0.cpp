class Solution {
public:
    int m,n;
    int dfs(vector<vector<int>>& grid,int r1,int c1,int r2,int c2,vector<vector<vector<vector<int>>>>& dp){
        // Out of bounds & Obstacles
        if(r1>=m || c1>=n || r2>=m || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return -1e9;
        }
        // Destination
        if(r1==m-1 && c1==n-1 && r2==m-1 && c2==n-1) return grid[r1][c1];  

        // Already calculated
        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];

        // Current Grid Value
        int current=grid[r1][c1];
        if(r1!=r2 || c1!=c2){
            current+=grid[r2][c2];
        }
        //Four Possibilities
        int DD = dfs(grid,r1+1,c1,r2+1,c2,dp);
        int DR = dfs(grid,r1+1,c1,r2,c2+1,dp);
        int RR = dfs(grid,r1,c1+1,r2,c2+1,dp);
        int RD = dfs(grid,r1,c1+1,r2+1,c2,dp);
        return dp[r1][c1][r2][c2] = current + max({DD,DR,RR,RD});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<vector<int>>>> dp(m,vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(n,-1))));
        if(grid[0][0]==-1 || grid[m-1][n-1]==-1) return 0;
        return max(0,dfs(grid,0,0,0,0,dp));
    }
};