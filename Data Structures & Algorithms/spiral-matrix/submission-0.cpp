class Solution {
public:
    void dfs(vector<vector<int>>& matrix,vector<int>& res,int n,int m,int r, int c, int dr,int dc){
        if(n==0 || m==0) return;
        for(int i=0;i<m;i++){
            r+=dr;
            c+=dc;
            res.push_back(matrix[r][c]);
        }
        dfs(matrix,res,m,n-1,r,c,dc,-dr);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> res;
        dfs(matrix,res,n,m,0,-1,0,1);
        return res;
    }
};
