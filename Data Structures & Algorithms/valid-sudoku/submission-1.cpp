class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> sets;
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.') continue;
                string row=string(1,board[r][c])+"Row"+to_string(r);
                string col=string(1,board[r][c])+"Col"+to_string(c);
                string box=string(1,board[r][c])+"Box"+to_string(r/3)+"_"+to_string(c/3);
                if(sets.find(row)!=sets.end() || sets.find(col)!=sets.end() || sets.find(box)!=sets.end()){
                    return false;
                }
                sets.insert(row);
                sets.insert(col);
                sets.insert(box);
            }
        }
        return true;
        
    }
};
