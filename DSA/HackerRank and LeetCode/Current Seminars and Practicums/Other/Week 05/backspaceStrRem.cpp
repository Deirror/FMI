class Solution {
public:
    string reworkStack(string str) {
        string res;
        for(auto ch : str) {
            if(ch >= 'a' && ch <= 'z') {
                res.push_back(ch);
            }
            else {
                if(res.length()) {
                    res.pop_back();
                }
            }
        }
        return res;
    }

    bool backspaceCompare(string s, string t) {
        s = reworkStack(s);
        t = reworkStack(t);
        return s == t;
    }
};
