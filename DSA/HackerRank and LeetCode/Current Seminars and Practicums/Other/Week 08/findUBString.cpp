class Solution 
{
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        for(int i = 0; i < nums.size(); i++) {
            res += to_string(!(nums[i][i]-'0'));
        }
        return res;    
    }
};
