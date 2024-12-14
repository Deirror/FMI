#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n, s;
    cin >> n >> s;
    
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }
    
    int days = 0;
    while(pq.size() > 1) {
        if(pq.top() < s) {
            int weakestPapay = pq.top();
            pq.pop();
            int infrontWeakestPapay = pq.top();
            pq.pop();
            pq.push(weakestPapay + (2 * infrontWeakestPapay));
            days++;
        } else {
            break;
        }
    }
    
    if(pq.size() == 1) {
        cout << -1;
    } else {
        cout << days;
    }

    return 0;
}
