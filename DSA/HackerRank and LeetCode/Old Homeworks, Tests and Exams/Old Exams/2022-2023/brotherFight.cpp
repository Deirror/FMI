#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ivanchoVec(n);
    vector<int> brotherVec(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ivanchoVec[i] = x;
    }    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        brotherVec[i] = x;
    }
    unordered_map<int, int> um;
    int hits = 0;
    for(int i = 0; i < n; i++) {
        um[ivanchoVec[i]]++;
        if(um.count(brotherVec[i])) {
            um[brotherVec[i]]--;
            if(um[brotherVec[i]] < 1) {
                um.erase(brotherVec[i]);
            }
        } else {
            hits++;
        }
    }
    cout << hits;
    return 0;
}
