class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> topoS;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int p:adjL[node]){
                inDegree[p]--;
                if(inDegree[p]==0) q.push(p);
            }
            topoS.push_back(node);
        }
        if(topoS.size()!=numCourses) return {};
        return topoS;
    }
};
