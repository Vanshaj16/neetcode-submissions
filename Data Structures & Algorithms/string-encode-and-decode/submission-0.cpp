class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(auto& it:strs){
            int n=it.length();
            res+= to_string(n)+"#"+it;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string ans="";
        int i=0;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            result.push_back(s.substr(j+1,len));
            i=j+len+1;
        }
        return result;
    }
};
