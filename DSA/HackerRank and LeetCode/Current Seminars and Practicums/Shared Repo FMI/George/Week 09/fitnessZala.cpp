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
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        if(p.first < p.second) {
            vec.emplace_back(p);
        }
    }
    sort(vec.begin(), vec.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxRes = 0;
    for(int i = 0; i < vec.size(); i++) {
        while(pq.size() && pq.top() <= vec[i].first) {
            pq.pop();
        }
        pq.push(vec[i].second);
        maxRes = max(maxRes, int(pq.size()));
    }
    cout << maxRes;
    return 0;
}
