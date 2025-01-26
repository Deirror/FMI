#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        map<int, int> m;
        int maxNum = 0;
        while(n--) {
            int k, x, y;
            cin >> k >> x >> y;
            maxNum = max(maxNum, max(x, y));
            m[x] += k;
            m[y] += -k;
        }
        int count = 0;
        for(int i = 0; i <= maxNum; i++) {
            if(m.count(i)) {
                count += m[i];
                if(count > c) {
                    break;
                }
            }
        }
        if(count > c) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}
