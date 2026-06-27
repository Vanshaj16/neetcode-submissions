class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& candidates,vector<int> curr,int target,int total,int idx){
        if(total==target){
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if(total+candidates[i]>target){
                break;
            }
            curr.push_back(candidates[i]);
            backtrack(candidates,curr,target,total+candidates[i],i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        backtrack(candidates,curr,target,0,0);
        return result;
    }
};
