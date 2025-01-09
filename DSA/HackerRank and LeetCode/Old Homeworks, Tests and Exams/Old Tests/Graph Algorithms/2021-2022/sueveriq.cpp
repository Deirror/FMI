#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<int> graph[2000][2000];


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y].insert(w);
    }
    int n;
    cin >> n;
    unordered_set<int> sueNums;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        sueNums.insert(num);
    }
    int path;
    cin >> path;
    for(int i = 0; i < path; i++) {
        int l;
        cin >> l;
    int f;
    cin >> f;
        bool flag = false;
    for(int j = 1; j < l; j++) {
        int c;
        cin >> c;   
        flag = false;
        for(auto nu : graph[f][c]) {
            if(!sueNums.count(nu)) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            break;
        }
        f = c;
    }
        if(!flag) {
            cout << '0';
        } else {
            cout << '1';
        }
    }
    return 0;
}
