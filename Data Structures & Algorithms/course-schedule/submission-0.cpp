class Solution {
private:
    bool dfs(int course,unordered_map<int,vector<int>>& mp, vector<int>& vis){
        if(vis[course]==1) return false;
        if(vis[course]==2) return true;
        vis[course]=1;
        for(auto& p:mp[course]){
            if(!dfs(p,mp,vis)) return false;
        }
        vis[course]=2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        for(auto& it:prerequisites){
            mp[it[0]].push_back(it[1]);
        }
        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,mp,vis)) return false;
        }
        return true;
    }
};