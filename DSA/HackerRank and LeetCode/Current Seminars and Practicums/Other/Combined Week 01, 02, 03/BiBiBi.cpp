#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        long long srch_num;
        cin >> srch_num;
        
        auto first_pos = lower_bound(arr.begin(), arr.end(), srch_num);     
        if(*first_pos != srch_num) {
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }      
        auto last_pos = upper_bound(arr.begin(), arr.end(), srch_num);
        
        cout << distance(arr.begin(), first_pos) + 1<< ' ' << distance(arr.begin(), last_pos) << '\n';
    }
    return 0;
}
