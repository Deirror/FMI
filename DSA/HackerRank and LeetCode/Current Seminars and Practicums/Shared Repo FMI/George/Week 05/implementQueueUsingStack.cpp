class MyQueue {
    int front = -1;
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(!st.size()) {
            front = x;
        }
        st.push(x);
    }
    
    int pop() {
        stack<int> tempSt;
        while(st.size()) {
            tempSt.push(st.top());
            st.pop();
        }
        int res = tempSt.top();
        tempSt.pop();
        if(!tempSt.size()) {
            front = -1;
            return res;
        }
        front = tempSt.top();
        while(tempSt.size()) {
            st.push(tempSt.top());
            tempSt.pop();
        }
        return res;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return st.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
