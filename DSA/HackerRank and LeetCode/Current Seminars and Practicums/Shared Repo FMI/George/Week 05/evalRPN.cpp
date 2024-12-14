class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> rpnCalcSt;
        for(auto& token : tokens) {
            if(!rpnCalcSt.size()) {
                rpnCalcSt.push(stoi(token));
            } else {
                if((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && (token[1] >= '0' && token[1] <= '9'))) {
                    rpnCalcSt.push(stoi(token));
                } else {
                    int fNum = rpnCalcSt.top();
                    rpnCalcSt.pop();
                    int sNum = rpnCalcSt.top();
                    rpnCalcSt.pop();
                    if(token[0] == '+') {
                        rpnCalcSt.push(fNum + sNum);
                    } else if(token[0] == '-') {
                        rpnCalcSt.push(sNum - fNum);
                    } else if(token[0] == '/') {
                        rpnCalcSt.push(sNum / fNum);
                    } else if(token[0] == '*') {
                        rpnCalcSt.push(fNum * sNum);
                    }
                }
            }
        }
        return rpnCalcSt.top();
    }
};
