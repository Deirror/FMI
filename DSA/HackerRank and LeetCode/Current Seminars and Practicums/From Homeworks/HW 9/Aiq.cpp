#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int groupsCount, cap;
        cin >> groupsCount >> cap;
        vector<pair<pair<int, int>, int>> v(groupsCount);
        for(int i = 0; i < groupsCount; i++) {
            int count, timeIn, timeOut;
            cin >> count >> timeIn >> timeOut;
            v[i] = {{timeIn, timeOut}, count};
        }
        sort(v.begin(), v.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        bool flag = true;
        int currSize = 0;
        for(int i = 0; i < v.size(); i++) {
            while(pq.size() && pq.top().first <= v[i].first.first) {
                currSize -= pq.top().second;
                pq.pop();
            }
            if(currSize + v[i].second > cap) {
                flag = false;
                break;
            }
            pq.push({v[i].first.second, v[i].second});
            currSize += v[i].second;
        }
        cout << flag << '\n';
    }
    return 0;
}
