class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        int i=1, prevLPS=0;
        vector<int> lps(n,0);
        while(i<n){
            if(needle[i]==needle[prevLPS]){
                lps[i]=prevLPS+1;
                prevLPS++;
                i++;
            }else if(prevLPS==0){
                lps[i]=0;
                i++;
            }else{
                prevLPS=lps[prevLPS-1];
            }
        }
        i=0;
        int j=0;
        while(i<m){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                if(j==0){
                    i++;
                }else{
                    j=lps[j-1];
                }
            }
            if(j==n) return i-n;
        }
        return -1;
    }
};