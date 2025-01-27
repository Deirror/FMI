#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

75/100

struct Artc {
    int idx, sold;
    
    bool operator<(const Artc& other) const {
        return sold <= other.sold;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<long long, int> m;
    long long maxTime = 0;
    while(n--) {
        long long id, time;
        cin >> id >> time;
        maxTime = max(maxTime, time);
        m[time] = id;
    }
    int k;
    cin >> k;
    vector<int> vec(k);
    for(int i = 0; i < k; i++) {
        int time;
        cin >> time;
        vec[i] = time;
        m[time] = -1;
    }
    unordered_map<int, int> timeUm;
    unordered_map<int, int> um;
    priority_queue<Artc> pq;
    for(auto& kvp : m) {
        if(kvp.second == -1) {
            if(pq.empty()) {
                timeUm[kvp.first] = -1;
            } else {
                timeUm[kvp.first] = pq.top().idx;
            }
        } else {
            um[kvp.second]++;
            pq.push({kvp.second, um[kvp.second]});
        }
    }
    for(auto x : vec) {
        cout << timeUm[x] << '\n';
    }
    return 0;
}
