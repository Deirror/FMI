#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unordered_map<string, int> um;
    int n, m;
    cin >> n >> m;
    for(int i =0; i < n; i++) {
        string str;
        cin >> str;
        int value;
        cin >> value;
        um[str] = value;
    }
    long long sum = 0;
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        sum += um[str];
    }
    cout << sum;
    return 0;
}
