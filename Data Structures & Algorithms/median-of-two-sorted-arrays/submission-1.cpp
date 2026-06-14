class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size();
        int s2=nums2.size();
        int total=s1+s2;
        int l1=0,l2=0; //Indexing of nums1 and nums2
        int prev=-1, curr=-1;
        for(int i=0;i<=total/2;i++){
            prev=curr;
            if(l1<s1 && (l2>=s2 || nums1[l1]<nums2[l2])){
                curr=nums1[l1++];
            }else{
                curr=nums2[l2++];
            }
        }
        if(total%2==0){
            return (prev+curr)/2.0;
        }
        return curr;
    }
};
