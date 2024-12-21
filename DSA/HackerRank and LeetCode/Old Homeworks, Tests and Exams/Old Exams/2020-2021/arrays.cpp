#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    int arr1[n]{};
    int arr2[m]{};
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    sort(arr1, arr1 + n);
    for(int i = 0; i < m; i++) {
        auto it = lower_bound(arr1, arr1 + n, arr2[i]);
        cout << it - arr1 << ' '; 
    }
    return 0;
}
