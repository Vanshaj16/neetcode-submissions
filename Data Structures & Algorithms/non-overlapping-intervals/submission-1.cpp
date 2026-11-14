class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]!=b[0]){
                return a[0]<b[0];
            }else return a[1]<b[1];
        });
        int result=0;
        vector<int> curr=intervals[0];
        for(int i=1;i<intervals.size();i++){
            vector<int> next = intervals[i];
            if(curr[1]>next[0]){
                if(curr[1]<=next[1]){
                    result++;
                }else{
                    curr=next;
                    result++;
                }
            }else{
                curr=next;
            }
        }
        return result;
    }
};