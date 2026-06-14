class Solution {
public:
    long long totalH(vector<int>& piles,int k){
        long long total=0;
        for(int p:piles){
            total+=(p+k-1)/k;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxP=*max_element(piles.begin(),piles.end());
        int i=1,j=maxP;
        int res=INT_MAX;
        while(i<=j){
            int mid=i+(j-i)/2;
            long long minH=totalH(piles,mid);
            if(minH<=h){
                res=mid;
                j=mid-1;
            }else i=mid+1;
        }
        return res;
    }
};
