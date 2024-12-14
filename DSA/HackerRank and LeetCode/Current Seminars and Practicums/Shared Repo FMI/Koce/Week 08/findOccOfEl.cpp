class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> vec;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == x) {
                vec.push_back(i);
            }
        }
        vector<int> res;
        for(auto query : queries) {
            if(query > vec.size()) {
                res.push_back(-1);
            } else {
                res.push_back(vec[query - 1]);
            }     
        }
        return res;
    }
};
