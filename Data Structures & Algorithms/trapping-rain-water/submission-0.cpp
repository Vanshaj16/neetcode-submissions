class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefixM(n);
        prefixM[0]=height[0];
        for(int i=1;i<n;i++){
            prefixM[i]=max(prefixM[i-1],height[i]);
        }
        vector<int> suffixM(n);
        suffixM[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixM[i]=max(suffixM[i+1],height[i]);
        }
        int res=0;
        for(int i=1;i<n-1;i++){
            res+=min(prefixM[i],suffixM[i])-height[i];
        }
        return res;
    }
};
