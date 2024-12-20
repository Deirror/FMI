#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_CITIES = int(1e6) + 1; 
vector<int> graph[MAX_CITIES * 2];
bool visited[MAX_CITIES * 2];

int bfs(int startIndex, int endIndex) {
    queue<int> q;
    q.push(startIndex);
    int level = 0;
    while(q.size()) {
        int size = q.size();
        level++;
        for(int i = 0; i < size; i++) {
            int vertex = q.front();
            visited[vertex] = true;
            for(auto connectedVertex : graph[vertex]) {
                if(endIndex == connectedVertex) {
                    return level;
                }
                if(!visited[connectedVertex]) {
                    q.push(connectedVertex);
                }
            }
            q.pop();
        }
    }
    return level;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        pair<int, int> edge;
        short len;
        cin >> edge.first >> edge.second >> len;
        if(len == 2) {
            graph[edge.first].push_back(MAX_CITIES + edge.first);
            graph[MAX_CITIES + edge.first].push_back(edge.second);
            
            graph[edge.second].push_back(MAX_CITIES + edge.second);
            graph[MAX_CITIES +edge.second].push_back(edge.first);
        } else if(len == 1) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
    }
    int startIndex, endIndex;
    cin >> startIndex >> endIndex;
    cout << bfs(startIndex, endIndex);
    return 0;
}
