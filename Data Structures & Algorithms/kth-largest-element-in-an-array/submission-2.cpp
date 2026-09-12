class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> minH;
        for(int p:nums){
            minH.push(p);
            if(minH.size()>k) minH.pop();
        }
        return minH.top();
    }
};
