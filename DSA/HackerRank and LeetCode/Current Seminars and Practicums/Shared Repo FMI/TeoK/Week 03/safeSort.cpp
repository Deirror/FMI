#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const string& lhs, const string& rhs) {
    int lhs_idx = 0, rhs_idx = 0;
    int counter = 1;
    int max_len = max(lhs.length(), rhs.length());
    while(counter <= max_len) {
        if(lhs[lhs_idx] > rhs[rhs_idx]) {
            return true;
        } else if(lhs[lhs_idx] < rhs[rhs_idx]) {
            return false;
        }
        
        lhs_idx = (++lhs_idx % lhs.length());
        rhs_idx = (++rhs_idx % rhs.length());   
        counter++;
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> vec(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    if(vec[0] == "0") {
        cout << 0;
        return 0;
    }
    
    for(auto& str : vec) {
        cout << str;
    }
    
    return 0;
}
