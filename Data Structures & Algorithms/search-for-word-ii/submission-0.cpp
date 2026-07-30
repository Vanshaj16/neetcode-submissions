class Solution {
private:
    bool check(vector<vector<char>>& board,string& word,vector<vector<bool>>& vis,int i,int j,int idx){
        if(idx==word.size()) return true;
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
            if(check(board,word,vis,r,c,idx+1)){
                vis[i][j]=false;
                return true;
            }
        }
        vis[i][j]=false;
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        set<string> res;
        for(string& word:words){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]==word[0]){
                        if(check(board,word,vis,i,j,0)){
                            res.insert(word);
                        }
                    }
                }
            }
        }
        return vector<string>(res.begin(),res.end());
    }
};
