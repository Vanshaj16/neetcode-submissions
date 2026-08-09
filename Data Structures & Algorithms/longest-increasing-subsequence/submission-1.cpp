class Solution {
public:
    int binaryS(vector<int>& res,int target){
        int l=0, r=res.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(res[mid]==target){
                return mid;
            }else if(res[mid]<target){
                l=mid+1;
            }else r=mid-1;
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            if(res.size()==0 || nums[i]>res.back()){
                res.push_back(nums[i]);
            }else{
                int idx=binaryS(res,nums[i]);
                res[idx]=nums[i];
            }
        }
        return res.size();
    }
};
