class StockSpanner {
public:
    stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stack<int> refS;
        refS=st;
        int res=1;
        while(!refS.empty()){
            if(price>=refS.top()){
                res++;
                refS.pop();
            }else break;
        }
        st.push(price);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */