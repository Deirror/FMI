#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < q; i++) {
        int min, max;
        cin >> min >> max;
        
        if(min > max) {
            cout << 0 << '\n';
            continue;
        }
        
        auto low_idx = lower_bound(arr.begin(), arr.end(), min);
        auto high_idx = upper_bound(arr.begin(), arr.end(), max);
        
        cout << high_idx - low_idx << '\n';
    }
    
    return 0;
}
