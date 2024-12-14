#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int max = n;
        int steps = 0;
        while(max > 0) {
            int mid = 1 + (max - 1) / 2;
            max -= mid;
            steps++;
        }
        cout << steps << '\n';
    }
    
    return 0;
}
