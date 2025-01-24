#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Line {
    int time, type;
    
    Line(int time, int type) : time(time), type(type) {}
    
    bool operator<(const Line& other) const {
        return time > other.time;
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
    
    return 0;
}
