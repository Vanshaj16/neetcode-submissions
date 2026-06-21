class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        int i=0;
        int maxVal=nums[0];
        int idx=0;
        for(int j=0;j<n;j++){
            if(nums[j]>=maxVal){
                maxVal=nums[j];
                idx=j;
            }
            if(j-i+1 == k){
                res.push_back(maxVal);
                if(i==idx && i+1<n){
                    idx=i+1;
                    maxVal=nums[idx];
                    for(int p=i+1;p<k+i;p++){
                        if(nums[p]>maxVal){
                            maxVal=nums[p];
                            idx=p;
                        }
                    }
                }
                i++;
            }
        }
        return res;
    }
};
