class Solution {
public:
    int trap(vector<int>& height) { // Monostack Approach T.C=O(n), S.C=O(n)
        int n=height.size();
        if(n==0) return 0;
        stack<int> st;
        int res=0;
        for(int i=0;i<n;i++){
            while(!st.empty() &&  height[st.top()]<=height[i]){
                int curr=height[st.top()];
                st.pop();
                if(!st.empty()){
                    int right = height[i];
                    int left=height[st.top()];
                    int h=min(right,left)-curr;
                    int w=i-st.top()-1;
                    res += h*w;
                }
            }
            st.push(i);
        }
        return res;
    }
};
