class Solution {
public:
    int maxDepth(string s) {
        int res=0;
        int p=0;
        for(char ch:s){
            if(ch=='('){
                p++;
                res=max(res,p);
            }else if(ch==')') p--;
        }
        return res;
    }
};