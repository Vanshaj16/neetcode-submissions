class Solution {
public:
    bool check(vector<vector<char>>& board,string& word,int w,int i,int j,int idx){
        if(idx==w) return true;
        int n=board.size();
        int m=board[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        int dirR[4]={-1,0,1,0};
        int dirC[4]={0,1,0,-1};
        bool res=false;
        for(int k=0;k<4;k++){
            int r=i+dirR[k];
            int c=j+dirC[k];
            if(check(board,word,w,r,c,idx+1)){
                board[i][j]=temp;
                return true;
            }
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int w=word.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(check(board,word,w,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
