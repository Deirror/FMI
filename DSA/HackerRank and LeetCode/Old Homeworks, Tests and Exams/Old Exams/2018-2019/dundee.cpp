#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string, int> mp;
    string str;
    while(cin >> str) {
        mp[str]++;
    }
    for(auto& kvp : mp) {
        if(kvp.second == 1) {
            cout << kvp.first << '\n';
        }
    }
    return 0;
}
