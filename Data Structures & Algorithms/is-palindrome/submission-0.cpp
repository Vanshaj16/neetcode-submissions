class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string t="";
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                t+=tolower(s[i]);
            }
        }
        int i=0, j=t.size()-1;
        while(i<j){
            if(t[i]!=t[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
