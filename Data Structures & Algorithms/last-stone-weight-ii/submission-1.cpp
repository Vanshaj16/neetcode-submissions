class Solution {
private:
    int dfs(int idx,int total,vector<int>& stones,int sum,int target,vector<vector<int>>& dp){
        // Base Case
        if(idx==stones.size() || total>=target){
            return abs(total-(sum-total));
        }
        if(dp[idx][total]!=-1) return dp[idx][total];
        int take=dfs(idx+1,total+stones[idx],stones,sum,target,dp);
        int notTake=dfs(idx+1,total,stones,sum,target,dp);
        return dp[idx][total]=min(take,notTake);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        int target=(sum+1)/2;
        vector<vector<int>> dp(stones.size(),vector<int>(target+1,-1));
        return dfs(0,0,stones,sum,target,dp);
    }
};