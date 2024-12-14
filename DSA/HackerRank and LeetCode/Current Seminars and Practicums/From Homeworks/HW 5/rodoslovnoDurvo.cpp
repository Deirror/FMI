#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool dfs(map<int, vector<int>>& mp, int parentVal, int childVal) {
    if(parentVal == childVal) {
        return true;
    }
    
    if(!mp[parentVal].size()) {
        return false;
    }
    
    bool flag = false;
    for(int i = 0; i < int(mp[parentVal].size()); i++) {
        flag = flag || dfs(mp, mp[parentVal][i], childVal);
        if(flag) {
            break;
        }
    }
    return flag;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for(int i = 0; i < n - 1; i++) {
        int parent, child;
        cin >> parent >> child;
        mp[parent].push_back(child);
        mp[child] = {};
    }
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int parentIdx, childIdx;
        cin >> parentIdx >> childIdx;
        auto parentIt = mp.begin();
        auto childIt = mp.begin();
        for(int i = 0; i < parentIdx; i++) {
            parentIt++;
        }
        for(int i = 0; i < childIdx; i++) {
            childIt++;
        }
        if(dfs(mp, parentIt->first, childIt->first)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }      
    }
    return 0;
}
