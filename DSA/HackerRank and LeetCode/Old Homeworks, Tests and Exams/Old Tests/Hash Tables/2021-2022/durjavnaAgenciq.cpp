#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unordered_map<int, int> um;   
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec[i] = num;
        um[num]++;
    }
    unordered_set<int> us = unordered_set<int>(vec.begin(), vec.end());
    for(int i = 0; i < n; i++) {
        if(um[vec[i]] == 1) {
            cout << vec[i] << ' ';
            us.erase(vec[i]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(!us.count(vec[i])) continue;
        cout << vec[i] << ' ';
        us.erase(vec[i]);
    }
    return 0;
}
