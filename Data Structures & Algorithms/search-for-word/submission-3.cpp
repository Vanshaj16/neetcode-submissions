class Solution {
public:
    bool check(vector<vector<char>>& board,string& word,int w,int i,int j,int idx,vector<vector<bool>>& vis){
        if(idx==w) return true;
        int n=board.size();
        int m=board[0].size();
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[idx] || vis[i][j]==true){
            return false;
        }
        vis[i][j]=true;
        int dirR[4]={-1,0,1,0};
        int dirC[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int r=i+dirR[k];
            int c=j+dirC[k];
            if(check(board,word,w,r,c,idx+1,vis)){
                vis[i][j]=false;
                return true;
            }
        }
        vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int w=word.size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(check(board,word,w,i,j,0,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
