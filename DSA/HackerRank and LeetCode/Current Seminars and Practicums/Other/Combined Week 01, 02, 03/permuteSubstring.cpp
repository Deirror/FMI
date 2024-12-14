#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

short hist[26];

int main() {
    string f, s;
    cin >> f >> s;
        
    for(int i = 0; i < f.length(); i++) {
        int idx = s.find(f[i]);
        
        if(idx != -1) {
            hist[f[i] - 'a']++;
            s[idx] = '\0';
        }
    }
    
    for(int i = 0; i < 26; i++) {
        if(hist[i] > 0) {
            for(int j = 0; j < hist[i]; j++) {
                cout << char(i + 'a');
            }
        }
    }
    
    return 0;
}
