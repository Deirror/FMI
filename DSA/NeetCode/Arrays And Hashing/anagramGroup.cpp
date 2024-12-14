class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        bool markedStrs[strs.size()]{};
        for(int i = 0; i < strs.size(); i++) {
            if(markedStrs[i]) continue;
            markedStrs[i] = true;
            vector<string> tempVec;
            tempVec.push_back(strs[i]);
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            for(int j = 0; j < strs.size(); j++) {
                if(i == j) {
                    continue;
                }
                string curr = strs[j];
                sort(curr.begin(), curr.end());
                if(temp == curr) {
                    markedStrs[j] = true;
                    tempVec.push_back(strs[j]);
                }
            }
            result.emplace_back(tempVec);
        }
        return result;
    }
};
