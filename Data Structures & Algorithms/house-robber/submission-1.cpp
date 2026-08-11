class Solution {
public:
    int rob(vector<int>& nums) {
        // Space optimised
        int prev2=0;
        int prev1=0;
        for(int money:nums){
            int robCurr=money+prev2;
            int skipCurr=prev1;
            int curr=max(robCurr,skipCurr);

            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
