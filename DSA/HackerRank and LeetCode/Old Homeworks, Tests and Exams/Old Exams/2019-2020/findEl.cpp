#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    vector<int> sv(n);
    for(int i = 0; i < n; i++) {
        cin >> sv[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        auto start = lower_bound(sv.begin(), sv.end(), x);
        if(start == sv.end()) {
            cout << sv.end() - sv.begin() << '\n';
        } else if(*start != x) {
            cout << (start) - sv.begin() << '\n';
        } else {
            auto last = upper_bound(sv.begin(), sv.end(), x);
            last--;
            cout << start - sv.begin() << ' ' << last - sv.begin() << '\n';
        }
    }
    return 0;
}
