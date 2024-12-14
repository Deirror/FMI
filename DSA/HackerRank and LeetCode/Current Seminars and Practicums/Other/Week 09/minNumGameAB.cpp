class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        vector<int> res;
        while(pq.size()) {
            int aliceNum = pq.top();
            pq.pop();
            int bobNum = pq.top();
            pq.pop();
            res.push_back(bobNum);
            res.push_back(aliceNum);
        }
        return res;
    }
};
