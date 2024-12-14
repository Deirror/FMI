class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<short> us;
        bool nullCount = false;
        for(auto num : arr) {
            if(!num) {
                if(nullCount) {
                    return nullCount;
                }
                nullCount = true;
            } else {
                    us.insert(num);
            }
        
        }
        for(auto num : us) {
            if(us.find(num * 2) != us.end()) {
                return true;
            }
        }
        return false;
    }
};
