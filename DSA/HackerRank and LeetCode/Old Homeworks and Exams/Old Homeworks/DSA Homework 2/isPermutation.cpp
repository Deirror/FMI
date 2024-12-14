#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hist1[26]{};
int hist2[26]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; 
    cin >> n;
       
    for(int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        hist1[ch - 'a']++;
    }
    
    for(int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        hist2[ch - 'a']++;
    }
    
    for(int i = 0; i < 26; i++) {
        if(hist1[i] != hist2[i]) {
            cout << "no";
            return 0;
        }
    }
    
    cout << "yes";
    
    return 0;
}
