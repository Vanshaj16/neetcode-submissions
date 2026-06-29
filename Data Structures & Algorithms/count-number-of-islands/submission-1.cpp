class Solution {
private:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int row,int col){
        int m=grid.size();
        int n=grid[0].size();
        vis[row][col]=1;
        int dirRow[]={-1,0,1,0};
        int dirCol[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int r=row+dirRow[i];
            int c=col+dirCol[i];
            if(r>=0 && r<m && c>=0 && c<n && !vis[r][c] && grid[r][c]=='1'){
                dfs(grid,vis,r,c);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    res++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return res;
    }
};
