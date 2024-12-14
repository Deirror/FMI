class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int counter = 0;

        std::sort(jewels.begin(), jewels.end());
        std::sort(stones.begin(), stones.end());

        for(int i = 0; i < jewels.length(); i++) {
            for(int j = 0; j < stones.length(); j++) {
                if(stones[j] > jewels[i]) {
                    break;
                }

                if(stones[j] == jewels[i]) {
                    counter++;
                }
            }
        }

        return  counter;
    }
};
