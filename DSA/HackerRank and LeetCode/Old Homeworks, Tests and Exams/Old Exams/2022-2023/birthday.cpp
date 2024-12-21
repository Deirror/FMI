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
    vector<pair<int, int>> times(n);
    for(int i = 0; i < n; i++) {
        cin >> times[i].first >> times[i].second;
    }
    int targetFriend ;
    cin >> targetFriend;
    vector<int> seatsIdx;
    for(int i = 0; i < times.size(); i++) {
        seatsIdx.push_back(i);
    }
    priority_queue<int, vector<int>, greater<int>> allSeats(seatsIdx.begin(), seatsIdx.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<pair<int,int>, int>> vec;
    for(int i = 0; i <times.size(); i++) {
        vec.push_back({{times[i].first, times[i].second}, i});
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) {
        while(pq.size() && pq.top().first <= vec[i].first.first) {
            allSeats.push(pq.top().second);
            pq.pop();
        }
        if(vec[i].second==targetFriend) {
            cout << allSeats.top();
            return 0;
        }
        pq.push({vec[i].first.second, allSeats.top()});
        allSeats.pop();
    }
    cout << -1;
    return 0;
}
