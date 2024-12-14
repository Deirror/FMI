class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp{};
        for(auto ch : s1) {
            mp[ch]++;
        }

        for(int i = 0; i < s2.length(); i++) {
            if(mp.find(s2[i]) != mp.end()) {
                unordered_map<char, int> temp = mp;
                bool flag = true;
                int j = i;
                while(flag && i < s2.length()) {
                    if(temp.find(s2[j]) != temp.end()) {
                        temp[s2[j]]--;
                        if(!temp[s2[j]]) {
                            temp.erase(s2[j]);
                        }
                        j++;
                    } else {
                        flag = false;
                    }
                }

                if(!temp.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};
