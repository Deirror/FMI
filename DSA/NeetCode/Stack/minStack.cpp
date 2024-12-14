class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> temp;
        int minNum = INT_MAX;
        while(st.size()) {
            minNum = min(minNum, st.top());
            temp.push(st.top());
            st.pop();
        }

        while(temp.size()) {
            st.push(temp.top());
            temp.pop();
        }
        return minNum;
    }
};
