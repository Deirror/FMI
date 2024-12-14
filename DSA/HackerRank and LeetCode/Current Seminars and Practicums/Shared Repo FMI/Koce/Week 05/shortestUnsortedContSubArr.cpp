class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = n, right = 0;
        deque<int> dq;

    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && nums[dq.back()] > nums[i]) {
            left = min(left, dq.back());
            dq.pop_back();
        }
        dq.push_back(i);
    }

    dq.clear();

    for (int i = n - 1; i >= 0; --i) {
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            right = max(right, dq.back());
            dq.pop_back();
        }
        dq.push_back(i);
    }
      
    if (right <= left) {
        return 0;
    }
    
    return right - left + 1;
    }
};
