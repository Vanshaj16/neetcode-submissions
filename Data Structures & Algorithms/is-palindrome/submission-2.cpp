class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                s[cnt++]=tolower(s[i]);
            }
        }
        int i=0, j=cnt-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
