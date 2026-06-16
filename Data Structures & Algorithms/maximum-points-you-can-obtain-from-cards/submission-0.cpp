class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int i=0;
        int leftSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        int j=n-1;
        int res=leftSum;
        int rightSum=0;
        for(int i=k-1;i>=0;i--){
            leftSum=leftSum-cardPoints[i];
            rightSum=rightSum+cardPoints[j];
            res=max(res,leftSum+rightSum);
            j--;
        }
        return res;
    }
};