#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = int(10e4);
int prices[MAX];

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    
    int win = 0;
    for(int i = 1; i < N; i++) {
        if(prices[i] > prices[i - 1]) {
            win += prices[i] - prices[i -1];
        }
    }
    
    cout << win;
    
    return 0;
}
