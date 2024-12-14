class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        if(k > nums.size()) {
            return -1;
        }

        for(int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
