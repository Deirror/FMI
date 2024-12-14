#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

short arr[int(10e4)];

int main() {
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int counter = 1;
    int sum = 0;
    
    for(int i = n - 1; i >= 0; i--, counter++) {
        if(counter < k) {
            sum += arr[i];
        } else {
            counter = 0;
        }
    }
    
    cout << sum;
    
    return 0;
}
