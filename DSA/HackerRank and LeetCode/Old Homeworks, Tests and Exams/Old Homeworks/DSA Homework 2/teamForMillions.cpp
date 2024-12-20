#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isUpper(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch) {
    return ch >= 'a' && ch <= 'z';
}

int main() {
    int hist[63]{};
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        
        if (isDigit(ch)) {
            hist[ch - '0' + 1]++;
        } else if (isLower(ch)){
            hist[ch - 'a' + 11]++;
        } else if (isUpper(ch)) {
            hist[ch - 'A' + 37]++;
        }
    }
    
    for(int i = 1; i < 63; i++) {
        
        if(hist[i] <= 0) continue;
        
        for(int j = 1; j <= hist[i]; j++) {
             if (i > 0 && i < 11) {
                 cout << i - 1;
             } else if (i > 10 && i < 37){
                 cout << char('a' + i - 11);
             } else if (i > 36 && i < 63) {
                 cout << char('A' + i - 37);
             }
        }
    }
    
    return 0;
}

