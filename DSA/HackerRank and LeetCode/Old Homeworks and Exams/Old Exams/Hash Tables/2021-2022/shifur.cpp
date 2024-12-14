#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    vector<string> vec(n);
    for(int i = 0; i < vec.size(); i++) {
        cin >> vec[i];
    }
    unordered_map<string, int> um;
    for(auto str : vec) {
        um[str]++;
    }
    for(auto str : vec) {
        cout << um[str] << ' ';
    }
    return 0;
}
