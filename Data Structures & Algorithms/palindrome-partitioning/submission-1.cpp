class Solution {
public:
    vector<vector<string>> res;
    bool palD(string& s,int l,int r){
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backTracking(string& s,int idx,vector<string>& cur){
        if(idx==s.size()){
            res.push_back(cur);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(palD(s,idx,i)){
                cur.push_back(s.substr(idx,i-idx+1));
                backTracking(s,i+1,cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        backTracking(s,0,cur);
        return res;
    }
};
