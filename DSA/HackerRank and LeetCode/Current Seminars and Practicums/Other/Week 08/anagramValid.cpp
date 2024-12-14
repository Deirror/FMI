class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> um;
        for(auto ch : s) {
            um[ch]++;
        }
        for(auto ch : t) {
            um[ch]--;
        }
        for(auto& kvp : um) {
            if(kvp.second) {
                return false;
            }
        }
        return true;
    }
};
