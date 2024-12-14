class Solution {
public:
    bool isLetter(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    string clearDigits(string s) {
        string res;
        for(auto ch : s) {
            if(!res.size()) {
                res.push_back(ch);
                continue;
            }

            if(isLetter(ch)) {
                res.push_back(ch);
            } else if(isDigit(ch)) {
                res.pop_back();
            }
        }
        return res;
    }
};
