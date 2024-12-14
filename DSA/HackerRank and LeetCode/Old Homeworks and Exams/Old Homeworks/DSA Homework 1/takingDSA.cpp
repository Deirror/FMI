#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int grades[int(10e5)];

int main() {
    short N;//min grade
    cin >> N;
    
    unsigned M;// student grades count
    cin >> M;
    
    for(int i = 0; i < M; i++) {
        cin >> grades[i];
    }
    
    sort(grades, grades + M);
    
    for(int i = 1; i < M; i++) {
        int diff = grades[i] - N;
        if(diff > 0) {
            grades[0] += diff;
            grades[i] -= diff;
        }
    }
    
    cout << ((grades[0] >= N) ? "yes" : "no");
    
    return 0;
}
