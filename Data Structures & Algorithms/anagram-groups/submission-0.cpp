class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> result;
        vector<bool> visited(n,false);
        for(int i=0;i<strs.size();i++){
            if (visited[i]) continue;
            string st=strs[i];
            sort(st.begin(),st.end());
            vector<string> curr;
            visited[i]=true;
            curr.push_back(strs[i]);
            for(int j=0;j<n;j++){
                if(visited[j]==false){
                    string s1=strs[j];
                    sort(s1.begin(),s1.end());
                    if(st==s1) {
                        curr.push_back(strs[j]);
                        visited[j]=true;
                    }
                }   
            }
            result.push_back(curr);
        }
        return result;
    }
};
