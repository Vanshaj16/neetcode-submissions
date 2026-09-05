class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;  // Stores the indexes
        int maxA=INT_MIN;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>heights[i])){
                int height=heights[st.top()];
                st.pop();
                
                int width=0;
                if(st.empty()){
                    width=i;
                }else{
                    width=i-st.top()-1; // Here the st.top() will be the previous the height one element.
                }
                maxA=max(maxA,height*width);
            }
            st.push(i);
        }
        return maxA;
    }
};
