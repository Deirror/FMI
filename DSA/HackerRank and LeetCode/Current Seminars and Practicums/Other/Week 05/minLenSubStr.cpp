class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(!st.empty() && st.top()=='A' && s[i]=='B') {
                st.pop();
            }
            else if(!st.empty() && st.top()=='C' && s[i]=='D') {
                st.pop();
            }
            else {
                st.push(s[i]);
            }       
        }    
        return st.size();
    }
};
