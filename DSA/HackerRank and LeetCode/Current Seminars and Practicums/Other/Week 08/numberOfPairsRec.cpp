class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> um;
        long long res = 0;
        for(auto& rectangle : rectangles) {
            res += um[rectangle[0] / double(rectangle[1])];
            um[rectangle[0] / double(rectangle[1])]++;
        } 
        return res;
    }
};
