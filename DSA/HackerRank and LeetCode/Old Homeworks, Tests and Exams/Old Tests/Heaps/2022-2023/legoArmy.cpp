#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    int times = 0;
    while(pq.size() > 1 && pq.top() < m) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x + 2 * y);
        times++;
        if(pq.top() >= m) {
            break;
        }
    }
    if(pq.top() >= m) {
        cout << times;
    } else {
        cout << -1;
    }
    return 0;
}
