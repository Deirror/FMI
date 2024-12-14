class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for(string str : strs) {
            string copy = str;
            sort(str.begin(), str.end());
            um[str].emplace_back(copy);
        }
        vector<vector<string>> res;
        for(auto& it : um) {
            res.emplace_back(it.second);
        }
        return res;
    }
};
