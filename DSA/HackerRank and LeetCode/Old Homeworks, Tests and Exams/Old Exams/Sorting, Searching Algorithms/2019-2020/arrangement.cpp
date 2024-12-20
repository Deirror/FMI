#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hist[100004];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        hist[num]++;
    }
    
    for(int i = 100000; i >= 0; i--) {
        if(hist[i] <= 0) continue;
        
        for(int j = 0; j < hist[i]; j++) {
            cout << i << ' ';
        }
    }
    
    return 0;
}
