class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq(score.begin(), score.end());
        unordered_map<int, string> um;
        for(int i = 1; i <= score.size(); i++) {
            int num = pq.top();
            pq.pop();
            switch(i) {
                case 1: {
                    um[num] = "Gold Medal";
                    break;
                }
                case 2: {
                    um[num] = "Silver Medal";
                    break;
                }
                case 3: {
                    um[num] = "Bronze Medal";
                    break;
                } 
                default: {
                    um[num] = to_string(i);
                }
            }
        }
        vector<string> res;
        for(auto num : score) {
            res.push_back(um[num]);
        }
        return res;
    }
};
