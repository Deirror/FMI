class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        vector<int> res;
        while(pq.size()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
