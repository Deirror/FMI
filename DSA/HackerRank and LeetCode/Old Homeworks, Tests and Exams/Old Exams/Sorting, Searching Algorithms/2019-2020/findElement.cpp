#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[int(10e4)];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int currQ;
        cin >> currQ;
        
        if(binary_search(arr, arr + n, currQ)) {
            cout << distance(arr, lower_bound(arr, arr + n, currQ)) << ' ';
            cout << distance(arr, upper_bound(arr, arr + n, currQ)) - 1<< '\n';
        } else {
             cout << distance(arr, upper_bound(arr, arr + n, currQ)) << '\n';
        }
    }
    
    return 0;
}
