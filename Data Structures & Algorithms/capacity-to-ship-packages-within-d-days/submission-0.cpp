class Solution {
public:
    int funcDays(vector<int>& weights,int cap){
        int days=1, load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                days++;
                load=weights[i];
            }else load+=weights[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int w:weights) high+=w;

        while(low<=high){
            int mid=low+(high-low)/2;
            int noDays=funcDays(weights,mid);
            if(noDays<=days){
                high=mid-1;
            }else low=mid+1;
        }
        return low;
    }
};