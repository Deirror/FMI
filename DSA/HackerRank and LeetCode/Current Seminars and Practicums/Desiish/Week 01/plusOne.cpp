#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long N;
    cin >> N;
    
    short arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    bool add = 1;
    for(int i = N - 1; i >= 0; i--) {
        short currDigit = arr[i];
        
        if(currDigit + 1 == 10 && add) {
            add = 1;
            arr[i] = 0;
        }
        else {
            arr[i] += add;
            add = 0;
        }
    }
    
    if(arr[0] == 0) cout << 1;
    
    for(int i = 0; i < N; i++) cout << arr[i];
    
    return 0;
}
