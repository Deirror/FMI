class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size());
        stack<int> st;
        for(int i = 0; i < prices.size(); i++) {
            while(st.size() && prices[st.top()] >= prices[i]) {
                res[st.top()] =  prices[st.top()] - prices[i];                      
                st.pop();
            }
            st.push(i);
        }
        while(st.size()) {
            res[st.top()] =  prices[st.top()];
            st.pop();
        }
        return res;  
    }
};
