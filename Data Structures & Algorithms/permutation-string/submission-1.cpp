class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int n1=s1.size();
        int n2=s2.size();
        int l=0;
        for(int r=l;r<n2;r++){
            if(r-l+1==n1){
                string t=s2.substr(l,r-l+1);
                sort(t.begin(),t.end());
                if(s1==t){
                    return true;
                }else{
                    l++;
                }
            }else if(r-l+1>n1) l++;
        }
        return false;
    }
};
