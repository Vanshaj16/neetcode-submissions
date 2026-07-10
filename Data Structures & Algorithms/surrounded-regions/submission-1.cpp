class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int r,int c,int dirR[],int dirC[]){
        int n=board.size();
        int m=board[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dirR[i];
            int nc=c+dirC[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(board,vis,nr,nc,dirR,dirC);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dirR[]={-1,0,1,0};
        int dirC[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(board,vis,0,i,dirR,dirC);
            }
            if(board[n-1][i]=='O'){
                dfs(board,vis,n-1,i,dirR,dirC);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,vis,i,0,dirR,dirC);
            }
            if(board[i][m-1]=='O'){
                dfs(board,vis,i,m-1,dirR,dirC);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
