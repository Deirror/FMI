class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(int i = 0; i < strs.size(); i++) {
            res += strs[i] + '|';
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int prev = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '|') {
                res.emplace_back(s.substr(prev, i - prev));
                prev = i + 1;
            }
        }
        return res; 
    }
};
