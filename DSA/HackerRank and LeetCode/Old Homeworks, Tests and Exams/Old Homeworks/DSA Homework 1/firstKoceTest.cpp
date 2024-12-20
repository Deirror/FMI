#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string sequence;
    cin >> sequence;
    
    char koceVariant;
    cin >> koceVariant;
    
    vector<int> koceVariantIndexes;
    
    koceVariantIndexes.emplace_back(-1);
    for(int i = 0; i < sequence.length(); i++) {
        if(sequence[i] == koceVariant) {
            koceVariantIndexes.emplace_back(i);
        }
    }
    koceVariantIndexes.emplace_back(-1);
    
    int idx1 = koceVariantIndexes[0], idx2 = koceVariantIndexes[1];
    int diff = 0;
    
    if(koceVariantIndexes.size() > 2) {
        for(int i = 0, j = 2; i < sequence.length(); i++) {
            
            if(idx1 == -1) {
                cout << idx2 - i << ' ';
            }
            else if(idx2 == -1) {
                cout << i - idx1 << ' ';
            }
            else {
                diff = (idx2 - idx1) / 2;
            
                if(i - idx1 <= diff) {
                    cout << i - idx1 << ' ';
                }
                else if (i - idx1 > diff) {
                    cout << idx2 - i << ' ';
                }
            }  
            
            if(idx2 - i == 0) {
                idx1 = idx2;
                idx2 = koceVariantIndexes[j++];
            }
        }
    }
    
    
    return 0;
}
