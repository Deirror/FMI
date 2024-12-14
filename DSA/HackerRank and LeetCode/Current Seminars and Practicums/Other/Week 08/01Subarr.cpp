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
    vector<char> v(n);
    vector<int> prefix(n);
    for(int i = 0; i < n; i++) {
        bool bit;
        cin >> bit;
        v[i] = (!bit ? -1 : bit);      
    }
    
    prefix[0] = v[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + v[i];      
    }
    
    int res = 0;
    unordered_map<int, int> um;
    for(int i = 0; i < n; i++) {
        if(!prefix[i]) {
            res = max(res, i);
        } else {
            if(um.find(prefix[i]) != um.end()) {
                res = max(res, i - um[prefix[i]]);
            } else {
                um[prefix[i]] = i;
            }
        }
    }
    cout << res;
    return 0;
}
