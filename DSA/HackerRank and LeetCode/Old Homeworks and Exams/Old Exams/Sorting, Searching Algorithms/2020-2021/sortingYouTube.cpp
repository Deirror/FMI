#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 7*int(10e3) + 1;

int hist[MAX_SIZE];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        hist[num]++;
    }
    
    for(int i = 0; i < MAX_SIZE; i++){
        if(hist[i] > 0) {
            cout << i << ' ';
        }
    }
    return 0;
}
