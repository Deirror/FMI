#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string, int> m;
    
    string word;
    while(cin >> word) {
        m[word]++;
    }

    for(auto& kvp : m) {
        if(kvp.second == 1) {
            cout << kvp.first << '\n';
        }
    }
    return 0; 
}
