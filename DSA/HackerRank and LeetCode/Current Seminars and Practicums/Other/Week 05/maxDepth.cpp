class Solution {
public:
    int maxDepth(string s) {
        size_t maxRes = 0;
        stack<char> st;
        for(auto ch : s) {
            if(ch == '(') {
                st.push(ch);
                maxRes = max(maxRes, st.size());
                
            } else if(ch == ')') {
                st.pop();
            }
        }
        int max = maxRes;
        return max;
    }
};
