class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<tuple<int, int, int*>, vector<tuple<int, int, int*>>, greater<tuple<int, int, int*>>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i, &nums[i]});
        }
        for(int i = 0; i < k; i++) {
            auto t = pq.top();
            pq.pop();
            int& num = get<0>(t);
            num *= multiplier;
            int& vecNum = *get<2>(t);
            vecNum *= multiplier;
            pq.push(t);
        }
        return nums;
    }
};
