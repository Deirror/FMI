// Exactly 1 Hour was needed to be accepted...........
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;

        auto beg = height.begin();
        auto end = height.end() - 1;

        while(end - beg > 1) {
            auto pot = beg + 1;
            while(pot != end && *beg <= *pot) {
                beg++;
                pot++;
            }
            if(pot == end) {
                break;
            }
            int remArea = 0;
            auto prev = beg;
            auto edgeCase = beg;
            bool flag = false;
            while(pot != height.end() && *beg > *pot) {
                remArea += *pot;
                if(*prev < *pot) {
                    flag = *prev < *pot;
                    edgeCase = pot;
                }
                pot++;
                prev++;
            }
            if(pot == height.end()) {
                if(flag) {
                    remArea = 0;
                    pot = beg + 1;
                    int currMin = min(*beg, *edgeCase);
                    while(pot != height.end() && pot != edgeCase) {
                        if(*pot > currMin) {
                            remArea += currMin;
                            pot++;
                            prev++;
                            continue;
                        }
                        remArea += *pot;
                        pot++;
                        prev++;
                    }
                } else {
                    break;
                }
            }
            res += (pot - beg - 1) * min(*pot, *beg) - remArea;
            beg = pot;
        }

        return res;
    }
};
