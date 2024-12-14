class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> um;
        for(int i = 0; i < s.length(); i++) {
            if(um.find(s[i]) != um.end()) {
                um[s[i]].first++;
            } else {
                um[s[i]] = make_pair(1, i);
            }
        }
        int res = INT_MAX;
        for(auto& kvp : um) {
            if(kvp.second.first == 1) {
                res = min(res, kvp.second.second);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
