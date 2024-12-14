class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s(candyType.begin(), candyType.end());
        size_t docTypes = candyType.size() / 2;
        return min(s.size(), docTypes);
    }
};
