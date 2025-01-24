#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Line {
    int time, type;
    
    Line(int time, int type) : time(time), type(type) {}
    
    bool operator<(const Line& other) const {
        if(time > other.time) {
            return true;
        } else if(time == other.time) {
            return type < other.type;
        }
        return false;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    priority_queue<Line> pq;
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pq.push({x, 1});
        pq.push({y, -1});
    }
    unordered_map<int, int> um;
    vector<int> vec(q);
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        vec[i] = x;
        pq.push({x, 0});
    }
    int curr = 0;
    while(pq.size()) {
        auto line = pq.top();
        pq.pop();
        if(line.type == 0) {
            um[line.time] = curr;
        }
        curr += line.type;
    }
    for(auto x : vec) {
        cout << um[x] << ' ';
    }
    return 0;
}
