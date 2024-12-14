#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int hist[5*int(10e4) - 1]{};   
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        hist[num] = 1;
    }
    
    for(int i = 0; i < 5*int(10e4) - 1; i++) {
        if(hist[i] == 1) {
            cout << i << ' ';
        }
    }
    
    return 0;
}
