
class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
    if (n == 0) return 0;

    stack<int> st;
    int totalWater = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty()) break;

            int distance = i - st.top() - 1;
            int boundedHeight = min(height[i], height[st.top()]) - height[top];
            totalWater += distance * boundedHeight;
        }

        st.push(i);
    }

    return totalWater;
    }
};
