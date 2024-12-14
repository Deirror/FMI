class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int hist[501];

        vector<vector<int>> res;

        for(int i = 0; i < groupSizes.size(); i++) {
            hist[groupSizes[i]]++;
        }

        for(int i = 1; i < 501; i++) {
            hist[i] /= i;
        }

        for(int i = 1; i < 501; i++) {
            if(hist[i] <= 0) continue;

            for(int j = 0; j < hist[i]; j++) {
                int counter = 0;
                vector<int> set;
                for(int t = 0; t < groupSizes.size(); t++) {
                    if(counter == i) break;

                    if(groupSizes[t] == i) {
                        counter++;
                        set.push_back(t);
                        groupSizes[t] = 0;
                    }
                }
                res.emplace_back(set);
            }
        }

        return res;
    }
};
