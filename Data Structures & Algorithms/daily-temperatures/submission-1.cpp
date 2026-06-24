class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>> st;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(0);
                st.push({temperatures[i],i});
            }else{
                while(!st.empty()){
                    if(st.top().first<=temperatures[i]){
                        st.pop();
                    }else{
                        ans.push_back(st.top().second-i);
                        break;
                    }
                }
                if(st.empty()) ans.push_back(0);
                st.push({temperatures[i],i});
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
