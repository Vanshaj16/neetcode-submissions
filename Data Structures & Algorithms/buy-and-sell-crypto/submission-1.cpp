class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0,j=1;
        int res=0;
        while(j<n){
            if(prices[j]>prices[i]){
                res=max(res,prices[j]-prices[i]);
            }else i=j;
            j++;
        }
        return res;
    }
};
