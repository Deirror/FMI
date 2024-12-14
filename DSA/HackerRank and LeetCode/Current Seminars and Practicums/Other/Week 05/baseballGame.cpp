class Solution {
public:
    bool areDigits(const string& str) {
        bool flag = false;
        for(auto ch : str) {
            if((ch < '0' || ch > '9') && ch != '-') {
                return false;
            }
        }
        return true;
    }

    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(const string& operation : operations) {
            if(areDigits(operation)) {
                st.push(stoi(operation));
            } else if(operation == "C") {
                st.pop();
            } else if(operation == "D") {
                st.push(st.top() * 2);
            } else if(operation == "+") {
                int fnum = st.top();
                st.pop();
                int snum = st.top();
                st.pop();
                st.push(snum);
                st.push(fnum);
                st.push(snum + fnum);
            }
        }

        int sum = 0;
        while(st.size()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
