class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    int trustMe[n + 1], trustOthers[n + 1];// or unordered map
    int res = -1;
    for(int i = 0; i < n + 1; i++){
        trustMe[i] = 0;
        trustOthers[i] = 0;
    }

    for(int i = 0; i < trustSize; i++){
        trustMe[trust[i][1]]++; 
        trustOthers[trust[i][0]]++; 
    }

    for(int i = 1; i < n + 1; i++){
        if(trustMe[i] == n - 1 && trustOthers[i] == 0)
            res = i;
    }
    return res;
    }
};
