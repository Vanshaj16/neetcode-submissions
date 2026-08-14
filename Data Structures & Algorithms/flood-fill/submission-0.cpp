class Solution {
public:
    int m,n;
    int dir[4][4]={{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(vector<vector<int>>& res,vector<vector<int>>& image,int sr,int sc,int prevC,int color){
        res[sr][sc]=color;
        for(int i=0;i<4;i++){
            int r=sr+dir[i][0];
            int c=sc+dir[i][1];
            if(r>=0 && r<m && c>=0 && c<n && res[r][c]!=color && image[r][c]==prevC){
                dfs(res,image,r,c,prevC,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        int prevC = image[sr][sc];
        vector<vector<int>> res=image;
        dfs(res,image,sr,sc,prevC,color);
        return res;
    }
};