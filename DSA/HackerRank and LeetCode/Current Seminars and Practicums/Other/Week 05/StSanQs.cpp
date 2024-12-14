class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stQ;
        queue<int> sanQ;

        for(auto st : students) {
            stQ.push(st);
        }

        for(auto san : sandwiches) {
            sanQ.push(san);
        }

        for(int i = 0; i < stQ.size(); i++) {
            if(stQ.front() == sanQ.front()) {
                stQ.pop();
                sanQ.pop();
                i = -1;
            } else {
                bool stPref = stQ.front();
                stQ.pop();
                stQ.push(stPref);
            }
        }
        return stQ.size();
    }
};
