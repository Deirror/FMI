#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int n, m;
        cin >> n >> m;
        unordered_map<int, unordered_set<int>> fg;
        int x, y;
        for(int i = 1; i <= n; i++) {
            fg[i] = unordered_set<int>();
        }
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            fg[x].insert(y);
            fg[y].insert(x);
        }
        unordered_map<int, unordered_set<int>> eg;
        for(auto& kvp : fg) {
            for(int i = 1; i <= n; i++) {
                if(kvp.second.find(i) == (kvp.second).end() && i != kvp.first) {
                    eg[kvp.first].insert(i);
                }      
            }
        }
        int ko;
        cin >> ko;
        vector<int> pathLens(n + 1, -1);
        queue<int> q;
        q.push(ko);
        bool checked[n + 1]{};
        int level = 0;
        while(q.size()) {
            int s = q.size();
            level++;
            for(int i = 0; i < s; i++) {
                int vertex = q.front();
                checked[vertex] = true;
                for(auto connectedVertex : eg[vertex]) {
                    if(!checked[connectedVertex]) {
                        q.push(connectedVertex);
                        checked[connectedVertex] = true;
                        pathLens[connectedVertex] = level;
                    }
                }
                q.pop();
            }
        }
        for(int i = 1; i <= n; i++) {
            if(pathLens[i] != -1) {
               cout << pathLens[i] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
