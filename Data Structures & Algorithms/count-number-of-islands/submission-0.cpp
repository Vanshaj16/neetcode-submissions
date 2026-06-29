class Solution {
private:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int row,int col){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        int dirRow[]={-1,0,1,0};
        int dirCol[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=r+dirRow[k];
                int ncol=c+dirCol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
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
                    bfs(grid,vis,i,j);
                }
            }
        }
        return res;
    }
};
