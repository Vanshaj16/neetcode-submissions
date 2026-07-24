class Solution {
public:
    bool res=false;
    void recursion(string s,string t,int i,int j){
        if(i==s.size()){
            res=true;
            return;
        }
        if(j==t.size() && i<s.size()){
            res=false;
            return;
        }
        if(s[i]==t[j]){
            recursion(s,t,i+1,j+1);
        }else{
            recursion(s,t,i,j+1);
        }
    }
    bool isSubsequence(string s, string t) {
        recursion(s,t,0,0);
        return res;
    }
};