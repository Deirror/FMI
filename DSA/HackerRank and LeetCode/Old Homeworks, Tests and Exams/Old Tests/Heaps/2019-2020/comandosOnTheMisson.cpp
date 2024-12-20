#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num != -1) {
            pq.push(num);
        } else {
            if(pq.size()) {
                cout << pq.top() << ' ';
                pq.pop();
            }
        }
    }
    return 0;
}
