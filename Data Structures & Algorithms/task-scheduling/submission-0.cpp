class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++; //char->freq
        }
        priority_queue<int> pq; //Max Heap
        for(auto& p:mp){
            pq.push(p.second);
        }
        int time=0;
        while(!pq.empty()){
            vector<int> temp;
            // If there is less CPU then n the process will include the idle and number remains n
            for(int i=1;i<=n+1;i++){  // The current element and the gap is from 1->n+1
                if(!pq.empty()){
                    temp.push_back(pq.top()-1); //Deducting the current CPU
                    pq.pop();
                }
            }
            for(int& freq:temp){
                if(freq>0){
                    pq.push(freq);
                }
            }
            if(pq.empty()){
                time+=temp.size();  //All processes finished
            }else{
                time+=(n+1); // n+1 tasks are finished in the above loop
            }
        }
        return time;
    }
};
