class Solution {
public:
    bool dfs(vector<vector<int>>& adjL,int node,vector<int>& vis){
        vis[node]=2;
        for(int p:adjL[node]){
            if(vis[p]==0 && dfs(adjL,p,vis)){
                return true;
            }else if(vis[p]==2) return true;
        }
        vis[node]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses);
        for(auto& it:prerequisites){
            adjL[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(dfs(adjL,i,vis)) return false; //dfs==true means cycle is present
        }
        return true;
    }
};