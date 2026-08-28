class Solution {
public:
    vector<vector<string>> res;
    bool isPalind(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string& s,int idx,vector<string>& cur){
        if(idx==s.length()){
            res.push_back(cur);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalind(s,idx,i)){
                string t=s.substr(idx,i-idx+1);
                cur.push_back(t);
                solve(s,i+1,cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        solve(s,0,cur);
        return res;
    }
};