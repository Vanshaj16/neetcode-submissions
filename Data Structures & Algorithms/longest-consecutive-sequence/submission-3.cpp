class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums),end(nums));
        int n=nums.size();
        if(n==0) return 0;
        int ans=0;
        for(auto v:nums){
            if(st.find(v-1)==st.end()){
                int cnt=1;
                int current=v;
                while(st.find(current+1)!=st.end()){
                    current++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};