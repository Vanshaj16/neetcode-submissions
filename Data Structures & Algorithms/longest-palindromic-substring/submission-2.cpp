class Solution {
public:
//Odd-Even Mid Expansion Approach T.C=O(n^2) S.C=O(1)
    void check(string& s,int i,int j,int n,int& start,int& maxL){
        while(i>=0 && j<n && s[i]==s[j]){
            if(j-i+1>maxL){
                start=i;
                maxL=j-i+1;
            }
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0,maxL=INT_MIN;
        for(int i=0;i<n;i++){
            check(s,i,i,n,start,maxL);
            check(s,i,i+1,n,start,maxL);
        }
        return s.substr(start,maxL);
    }
};