#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool check(int num, int subNum) {
    while(num && subNum) {
        bool bit = num % 2;
        bool subBit = subNum % 2;
        if(!bit && subBit) {
            return false;
        }
        num >>= 1;
        subNum >>= 1;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    unordered_set<int> us;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for(int j = 0; j <= num; j++) {
            if(check(num, j)) {
                us.insert(j);
            }
        }
    }
    cout << us.size();
    return 0;
}
