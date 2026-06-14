class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0, j=n-1;
        int res=INT_MIN;
        while(i<j){
            int water=min(heights[i],heights[j])*(j-i);
            res=max(res,water);
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return res;
    }
};
