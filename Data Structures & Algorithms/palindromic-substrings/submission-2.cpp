class Solution {
public:
//Odd, Even Center(Smart Approach)
    void check(string& s,int i,int j,int n,int& cnt){
        while(i>=0 && j<n && s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            check(s,i,i,n,cnt);
            check(s,i,i+1,n,cnt);
        }
        return cnt;
    }
};
