class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<int, pair<int, int>> occMp;
        for(int i = 0; i < s.length(); i++) {
            if(occMp.find(s[i]) != occMp.end()) {
                occMp[s[i]].second = i;
            } else {
                occMp[s[i]] = make_pair(i, i);
            }
        }
        int maxDist = -1;
        for(auto& kvp : occMp) {
            auto idxPair = kvp.second;
            maxDist = max(maxDist, idxPair.second - idxPair.first - 1);
        }
        return maxDist;
    }
};
