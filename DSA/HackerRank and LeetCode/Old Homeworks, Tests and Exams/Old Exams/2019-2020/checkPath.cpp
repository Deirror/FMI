#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef struct WeightedVertexInfo {
    int data;
    int weight;
    
    WeightedVertexInfo(int data, int weight) : data(data), weight(weight) {
        
    }
    
    bool operator<(const WeightedVertexInfo& other) const {
        return data < other.data;
    }
} WV;

bool operator==(const WeightedVertexInfo& lhs, const WeightedVertexInfo& rhs) {
    return lhs.data == rhs.data;
}

set<WV> graph[int(1e4) + 1];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].insert(WV(y, w));
        graph[y].insert(WV(x, w));
    }
    int k;
    cin >> k;
    int f;
    cin >> f;
    int sum = 0;
    for(int i = 1; i < k; i++) {
        int c;
        cin >> c;
        auto it = graph[f].find(WV(c, 0));
        if(it != graph[f].end()) {
            sum += (*it).weight;
        } else {
            cout << -1;
            return 0;
        }
        f = c;
    }
    cout << sum;
    return 0;
}
