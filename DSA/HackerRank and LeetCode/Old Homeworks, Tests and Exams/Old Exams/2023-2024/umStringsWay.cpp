#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        unordered_map<char, short> um;
        for(auto ch : str) {
            um[ch]++;
        }
        bool flag = false;
        for(auto& kvp : um) {
            --kvp.second;
            unordered_set<int> us;
            for(auto& check : um) {
                if(check.second == 0) continue;
                us.insert(check.second);
            }
            kvp.second++;
            if(us.size() == 1 || us.size() == 0) {
                flag = true;
                break;
            }
        }
        if(flag) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
