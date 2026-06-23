class MinStack {
public:
    stack<int> st;
    stack<int> minStk;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStk.empty() || val<=minStk.top()){
            minStk.push(val);
        }
    }
    
    void pop() {
        if(st.top()==minStk.top()){
            minStk.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
