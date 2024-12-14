#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int k;
    cin >> k;
    int x, y;
    vector<int> graph[int(1e5) + 1]{};
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> q;
    q.push(0);
    bool checked[int(1e5) + 1]{};
    int sum = 0;
    int level = 0;
    while(q.size()) {
        int s = q.size();
        level++;
        for(int i = 0; i < s; i++) {
            int vertex = q.front();
            checked[vertex] = true;
            for(auto connectedVertex : graph[vertex]) {
                if(!checked[connectedVertex]) {
                    q.push(connectedVertex);
                    checked[connectedVertex] = true;
                    sum += level;
                }
            }
            q.pop();
        }
    }
    cout << sum;
    return 0;
}
