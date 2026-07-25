class Solution {
public:
    vector<vector<string>> res;
    bool palI(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string& s,vector<string>& cur,int i,int j){
        if(j>=s.size()){
            if(i==j){
                res.push_back(cur);
            }
            return;
        }
        if(palI(s,i,j)){
            cur.push_back(s.substr(i,j-i+1));
            solve(s,cur,j+1,j+1);
            cur.pop_back();
        }
        solve(s,cur,i,j+1);
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        solve(s,cur,0,0);
        return res;
    }
};
