class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size() < k) {
            return {};
        }
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        for(const auto& point : points) {
            pq.push({sqrt(point[0] * point[0] + point[1] * point[1]), {point[0], point[1]}});
        }
        vector<vector<int>> res(k, vector<int>(2));
        for(int i = 0; i < k; i++) {
            auto kvp = pq.top().second;
            pq.pop();
            res[i] = {kvp.first, kvp.second};
        }
        return res;
    }
};
