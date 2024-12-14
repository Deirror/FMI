#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int touristX, touristY, n, k;  
    cin >> touristX >> touristY >> n >> k;
    priority_queue<pair<double, pair<int, int> >, vector<pair<double, pair<int, int> >>, std::greater<pair<double, pair<int, int> >> > pq;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pq.push(make_pair(double(sqrt(pow(x - touristX, 2) + pow(y - touristY, 2))), make_pair(x, y)));
    }
    for(int i = 0; i < k && pq.size(); i++) {
        auto kvp = pq.top().second;
        pq.pop();
        cout << kvp.first << ' ' << kvp.second << '\n';
    }
    
    return 0;
}
