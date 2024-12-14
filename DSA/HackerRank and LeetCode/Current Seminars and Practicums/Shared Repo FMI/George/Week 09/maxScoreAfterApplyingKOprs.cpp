class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long sum = 0;
        for(int i = 0; i < k && pq.size(); i++) {
            long long num = pq.top();
            pq.pop();
            sum += num;
            pq.push(ceil(num / 3.0));
        }
        return sum;
    }
};
