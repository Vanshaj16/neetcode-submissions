class Solution {
public:
    bool validBox(int sr,int er,int sc,int ec,unordered_set<char>& sets,vector<vector<char>>& board){
        for(int r=sr;r<=er;r++){
            for(int c=sc;c<=ec;c++){
                if(board[r][c]=='.') continue;
                if(sets.find(board[r][c])!=sets.end()){
                    return false;
                }
                sets.insert(board[r][c]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // Row Check
        unordered_set<char> sets;
        bool check=true;
        for(int r=0;r<9;r++){
            sets.clear();
            for(int c=0;c<9;c++){
                if(board[r][c]=='.') continue;
                if(sets.find(board[r][c])!=sets.end()){
                    return false;
                }
                sets.insert(board[r][c]);
            }
        }
        // Column Check
        for(int c=0;c<9;c++){
            sets.clear();
            for(int r=0;r<9;r++){
                if(board[r][c]=='.') continue;
                if(sets.find(board[r][c])!=sets.end()){
                    return false;
                }
                sets.insert(board[r][c]);
            }
        }
        //Grid Box Check
        for(int sr=0;sr<9;sr+=3){
            int er=sr+2;
            for(int sc=0;sc<9;sc+=3){
                int ec=sc+2;
                sets.clear();
                if(!validBox(sr,er,sc,ec,sets,board)){
                    return false;
                }
            }
        }
        return true;
    }
};
