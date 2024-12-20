#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
    int fCount, sCount;
    cin >> fCount >> sCount;
        
    unordered_map<string, int> fSentanceMap;
    unordered_map<string, int> sSentanceMap;
        
    string word;
    while(fCount--) {
        cin >> word;
        fSentanceMap[word]++;
    } 
    while(sCount--) {
        cin >> word;
        sSentanceMap[word]++;
    }   
    for(auto& kvp : fSentanceMap) {
        if(sSentanceMap.find(kvp.first) != sSentanceMap.end()) {
            if(kvp.second >= sSentanceMap[kvp.first]) {
                sSentanceMap.erase(kvp.first);
            } else {
                break;
            }
        }
    }
    if(sSentanceMap.size()) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    }
    return 0;
}
