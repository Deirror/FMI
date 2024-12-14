#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[int(1e6)];

int main() {
    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    for(int i = 0; i < q; i++) {
        int min, max;
        cin >> min >> max;
        
        if(min > max){
            cout << 0 <<'\n';
            continue;
        }
      
        auto min_idx = lower_bound(arr, arr + n, min);
        auto max_idx = upper_bound(arr, arr + n, max);      
        
        cout << abs(max_idx - min_idx) << '\n';
    }
    
    return 0;
}
