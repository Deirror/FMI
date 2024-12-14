#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    unordered_map<int, int> um;
    int res = INT_MAX;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(um.find(num) != um.end()) {
            res = min(res, i - um[num]);
        }
        um[num] = i;
    }
    cout << res;
    return 0;
}
