class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int c=0;
    KthLargest(int k, vector<int>& nums) {
        for(int num:nums){
            pq.push(num);
        }
        c=k;
    }
    int add(int val) {
        pq.push(val);
        while(pq.size()>c){
            pq.pop();
        }
        return pq.top();
    }
};
