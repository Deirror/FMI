#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int maxLen = 0;
    int mostLeft = 0;
    unordered_set<int> us;
    for(int i = 0; i < n; i++) {
        while(us.find(v[i]) != us.end()) {
            us.erase(v[mostLeft++]);
        }
        us.insert(v[i]);
        maxLen = max(maxLen, (int)us.size());
    }
    cout << maxLen;
    return 0;
}
