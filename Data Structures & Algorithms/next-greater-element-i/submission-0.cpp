class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2=nums2.size();
        unordered_map<int,int> mp;
        stack<int> st;
        vector<int> res;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            mp[nums2[i]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        for(int p:nums1){
            res.push_back(mp[p]);
        }
        return res;
    }
};