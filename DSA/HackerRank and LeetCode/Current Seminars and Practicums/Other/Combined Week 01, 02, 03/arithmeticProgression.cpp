class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = std::abs(arr[0] - arr[1]);
        for(int i = 1; i < arr.size() - 1; i++) {
            int currDiff = std::abs(arr[i] - arr[i + 1]);
            if(currDiff != diff) {
                return false;
            }
        }

        return true;
    }
};
