#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> graph[int(1e6) + 1];
unordered_set<int> friends;

int bfs(int startVertex) {
    queue<int> q;
    q.push(startVertex);
    unordered_set<int> visited;
    int level = 0;
    while(q.size()) {
        int size = q.size();
        level++;
        for(int i = 0; i < size; i++) {
            int vertex = q.front();
            if(friends.find(vertex) != friends.end() && vertex != startVertex) {
                    return level;
            }
            visited.insert(vertex);
            for(auto connectedVertex : graph[vertex]) {
                if(visited.find(connectedVertex) == visited.end()) {
                    visited.insert(connectedVertex);
                    q.push(connectedVertex);
                }
            }
            q.pop();
        }
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        pair<int, int> edge;
        cin >> edge.first >> edge.second;   
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }
    vector<int> groups(n);
    for(int i = 0; i < n; i++) {
        cin >> groups[i];
    }
    int myGroup;
    cin >> myGroup;
    for(int i = 0; i < n; i++) {
        if(groups[i] == myGroup) {
            friends.insert(i + 1);
        }
    }
    int minDist = INT_MAX;
    for(auto num : friends) {
        int dist = bfs(num);
        if(dist) {
            minDist = min(minDist, dist);
        }
    }
    if(minDist == INT_MAX) {
        cout << -1;
    } else {
        cout << minDist - 1;
    }
    return 0;
}
