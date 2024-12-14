#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    short N;
    int K;
    cin >> N >> K;
    
    vector<int> vec;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        if(num != K)
        vec.push_back(num);
    }
    
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
        
    return 0;
}
