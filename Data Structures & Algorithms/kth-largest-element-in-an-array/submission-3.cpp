class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxH;
        for(int p:nums){
            maxH.push(p);
        }
        for(int i=0;i<k-1;i++){
            maxH.pop();
        }
        return maxH.top();
    }
};
