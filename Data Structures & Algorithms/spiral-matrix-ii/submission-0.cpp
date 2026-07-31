class Solution {
public:
    void dfs(vector<vector<int>>& res,int n,int m,int r,int c,int dr,int dc,int num){
        if(n==0 || m==0) return;
        for(int i=0;i<m;i++){
            r+=dr;
            c+=dc;
            res[r][c]=num++;
        }
        dfs(res,m,n-1,r,c,dc,-dr,num);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        dfs(res,n,n,0,-1,0,1,1);
        return res;
    }
};