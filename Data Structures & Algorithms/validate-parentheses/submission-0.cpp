class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char p:s){
            if(st.empty() || p=='(' || p=='{' || p=='['){
                st.push(p);
            }else if(p==')'){
                if(st.top()=='('){
                    st.pop();
                }else return false;
            }else if(p=='}'){
                if(st.top()=='{'){
                    st.pop();
                }else return false;
            }else if(p==']'){
                if(st.top()=='['){
                    st.pop();
                }else return false;
            }
        }
        return st.empty();
    }
};
