class Solution {
public:
    double myPow(double x, int n) {
        long long p=n;
        if(p<0) p=abs(p);
        double ans=1.0;
        while(p){
            if(p%2==1){
                ans=ans*x;
                p--;
            }else{
                x*=x;
                p/=2;
            }
        }
        if(n<0) ans=1.0/ans;
        return ans;
    }
};
