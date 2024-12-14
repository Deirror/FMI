#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = int(10e4) + 1;
int hist1[MAX_SIZE]{};
int hist2[MAX_SIZE]{};

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i <N; i++) {
        int num;
        cin >> num;
        hist1[num]++;
    }
    
    int M;
    cin >> M;

    for(int i = 0; i <M; i++) {
       int num;
        cin >> num;
        hist2[num]++;
    }
    
    long long sum = 0;
    for(int i = 0; i < MAX_SIZE; i++) {
        if(hist1[i] > 0 && hist2[i] > 0) {
            sum += i;
        }
    }
    
    cout << sum;
    return 0;
}
