#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool has_cycle(int v, vector<int>* graph, bool* visited) {
    visited[v] = true;
    for(auto cv : graph[v]) {
        if(visited[cv]) {
            return true;
        }
        if(has_cycle(cv, graph, visited)) {
            return true;
        }
    }
    visited[v] = false;
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int v, e;
        cin >> v >> e;
        vector<int> graph[10001]{};
        for(int j = 0; j < e; j++){
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].push_back(y);
        }
        bool visited[10001]{};
        bool flag = false;
        for(int i = 1; i <= v; i++) {
            if(!visited[i]) {
                if(has_cycle(i, graph, visited)) {
                    flag = true;
                    break;
                }
            }
        }
        cout << flag;
    }
    return 0;
}
