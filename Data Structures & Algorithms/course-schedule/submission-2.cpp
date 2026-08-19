class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses);
        vector<int> inDegree(numCourses,0);
        for(auto& it:prerequisites){
            adjL[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int p:adjL[node]){
                inDegree[p]--;
                if(inDegree[p]==0) q.push(p);
            }
        }
        if(count==numCourses) return true;
        return false;
    }
};