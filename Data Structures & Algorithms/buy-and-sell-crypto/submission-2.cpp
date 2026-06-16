class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int res=0;
        int minB=prices[0];
        for(int i=1;i<n;i++){
            res=max(res,prices[i]-minB);
            minB=min(minB,prices[i]);
        }
        return res;
    }
};
