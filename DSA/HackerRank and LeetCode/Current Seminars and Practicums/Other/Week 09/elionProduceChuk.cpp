#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num == -1) {
            if(pq.size() > 0) {
            cout << pq.top() << ' ';
            pq.pop();
            }
        } else {
            pq.push(num); 
        }
    }
    return 0;
}
