#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr1[int(10e4)];
int arr2[int(10e4)];

int main() {
    int n,m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    
    sort(arr1, arr1 + n);
    
    for(int i = 0; i < m; i++) {
        cout << distance (arr1, lower_bound(arr1, arr1 + n, arr2[i])) << ' ';     
    }
    
    return 0;
}
