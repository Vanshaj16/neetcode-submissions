class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int minEnd=INT_MAX;
        int maxEnd=INT_MIN;
        for(auto& it:intervals){
            minEnd=min(minEnd,it[1]);
            maxEnd=max(maxEnd,it[1]);
        }
        int offset = -minEnd;
        int range = maxEnd-minEnd;

        vector<int> bestStart(range+1,INT_MIN); // Take maximum start for each end time
        for(auto& it:intervals){
            int start = it[0];
            int end = it[1];

            int index = end+offset;
            bestStart[index] = max(bestStart[index],start);
        }
        int kept=0;
        int lastEnd=INT_MIN;

        for(int i=0;i<=range;i++){
            if(bestStart[i]==INT_MIN) continue;
            if(bestStart[i] >= lastEnd){
                kept++;
                lastEnd = i-offset;
            }
        }
        return n-kept;
    }
};
