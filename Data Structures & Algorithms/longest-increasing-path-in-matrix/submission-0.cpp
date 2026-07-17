class Solution {
public:
    int dfs(vector<vector<int>>& matrix,int r,int c,vector<vector<int>>& dp){
        int n=matrix.size();
        int m=matrix[0].size();
        int dirR[4]={-1,0,1,0};
        int dirC[4]={0,1,0,-1};
        if(dp[r][c]!=-1) return dp[r][c];
        int ans=1;
        for(int i=0;i<4;i++){
            int nr=r+dirR[i];
            int nc=c+dirC[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[r][c]){
                ans=max(ans,1+dfs(matrix,nr,nc,dp));
            }
        }
        return dp[r][c]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int res=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=max(res,dfs(matrix,i,j,dp));
            }
        }
        return res;
    }
};
