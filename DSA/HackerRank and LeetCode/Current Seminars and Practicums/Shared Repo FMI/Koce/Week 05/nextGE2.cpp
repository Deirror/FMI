class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> st;
        for(int i = 0; i < nums.size(); i++) {
            while(st.size() && nums[st.top()] < nums[i]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        while(st.size()) {
            int idx = st.top();
            st.pop();
            for(int i = 0; i < idx; i++){
                if(nums[i] > nums[idx]) {
                    res[idx] = nums[i];
                    break;
                }
            }
        }

        return res;
    }
};
