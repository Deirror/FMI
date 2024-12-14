class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        for(auto ch : tasks) {
            m[ch]++;
        }
        int res = 0;
        while(m.size()) {
            int times = 0;
            for(auto& kvp : m) {
                kvp.second--;
                times++;
                if(!kvp.second) {
                    m.erase(kvp.first);
                }
            }
            res += times;
            if(!m.size()) {
                break;
            }
            if(times > n) continue;
            res += (n - times + 1);
        }
        return res;
    }
};
