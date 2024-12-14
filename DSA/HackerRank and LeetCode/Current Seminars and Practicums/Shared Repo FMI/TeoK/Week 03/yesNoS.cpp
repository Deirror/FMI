#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int hist[26]{};
    
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        hist[str[i] - 'a']++;       
    }
    
    auto max = max_element(hist, hist + 26);
    int ch_counter = 1;
    while(*max > 1 && ch_counter) {
        int max_idx = distance(hist, max);
        ch_counter = 0;
        for(int i = 0; i < 26; i++) {
            if(hist[i] > 0 && i != max_idx) {
                while(hist[i] && hist[max_idx]) {
                    hist[max_idx]--;
                    hist[i]--;
                }
                ch_counter++;
            }
            
            if(!hist[max_idx]) {
                break;
            }
        }
        max = max_element(hist, hist + 26);
    }
    if(*max <= 1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
