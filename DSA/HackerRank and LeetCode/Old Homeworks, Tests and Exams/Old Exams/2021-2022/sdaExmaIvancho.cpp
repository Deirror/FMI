#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

void bfs(int v, unordered_set<int>* graph, bool* visited, vector<int>& dist) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    int level = 6;
    while(q.size()) {
        int s = q.size();
        for(int i = 0; i < s; i++) {
            int fv = q.front();
            q.pop();
            for(auto cv : graph[fv]) {
                if(!visited[cv]) {
                    visited[cv] = true;
                    q.push(cv);
                    dist[cv] = level;
                }
            }      
        } 
        level += 6;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int n, m;
        cin >> n >> m;
        unordered_set<int> graph[n + 1]{};
        bool visited[n + 1]{};
        for(int j = 0; j < m; j++) {
            int x, y;
            cin >> x >> y;
            graph[x].insert(y);
            graph[y].insert(x);
        }
        int ivancho;
        cin >> ivancho;
        vector<int> dist(n + 1, -1);
        bfs(ivancho, graph, visited, dist);
        for(int i = 1; i <= n; i++) {
            if(i != ivancho) {
                cout << dist[i] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
