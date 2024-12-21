#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    cin.ignore();
    
    unordered_map<string, int> rows;
    
    for(int i = 0; i < N; i++) {
        char buff[M*2];    
        cin.getline(buff, M*2);
        
        string row(buff);
        rows[row]++;
    }
    
    int counter = 0;
    for(const auto& row : rows) {
        if(row.second == 1) {
            counter++;
        }
    }
    
    cout << counter;
    
    return 0;
}
