class Solution {
public:
    std::vector<std::string> split(std::string const &input) { 
    std::istringstream buffer(input);
    std::vector<std::string> ret((std::istream_iterator<std::string>(buffer)), 
                                 std::istream_iterator<std::string>());
    return ret;
}

    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> um;
        vector<string> vs1 = split(s1);
        vector<string> vs2 = split(s2);
        for(auto str : vs1) {
            um[str]++;
        }
        for(auto str : vs2) {
            um[str]++;
        }
        vector<string> res;
        for(auto& kvp : um) {
            if(kvp.second == 1) {
                res.emplace_back(kvp.first);
            }
        }
        return res;
    }
};
