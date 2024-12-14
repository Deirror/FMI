class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;
        bool flag = false;
        for(auto s : word) {
            st.push(s);
            if(s == ch) {
                flag = true;
                break;
            }
        }

        if(!flag) {
            return word;
        }

        auto beg = word.begin();
        while(st.size()) {
            *beg = st.top();
            st.pop();
            beg++;
        }
        return word;
    }
};
