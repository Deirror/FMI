#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    unordered_map<int, int> um;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        um[num] = (um[num] + 1) % 10;
    }
    int clients = 0;
    int to_deliver = 0;
    for(auto& kvp : um) {
        if(kvp.second != 0) {
            clients++;
        }
        to_deliver += kvp.second;
    }
    cout << clients << ' ' << to_deliver;
    return 0;
}
