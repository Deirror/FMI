
class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1) {
            return false;
        }
        stack<char> st;
        for(auto ch : s) {
            if(ch == '[' || ch == '{' || ch == '(') {
                st.push(ch);
            } else if(st.size() && ((ch == ']' && st.top() == '[') || (ch == '}' && st.top() == '{') || (ch == ')' && st.top() == '('))) {
                st.pop();
            } else {
                return false;
            }
        }
        return !st.size();
    }
};
