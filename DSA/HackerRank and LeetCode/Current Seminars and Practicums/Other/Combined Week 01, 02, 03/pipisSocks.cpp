#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int arr[1000];

int main() {
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int size = 0;
    for(int i = n - 1; i >= 0; i--) {
        size += i;
    }
    
    std::tuple<int, int, int> sockPairInfo[size];
    
    int idx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            sockPairInfo[idx++] = std::make_tuple(std::abs(arr[i] - arr[j]),arr[i], arr[j]);
        }
    }
    
    sort(sockPairInfo,  sockPairInfo + size);
    
    auto res = sockPairInfo[k - 1];  
    cout << std::get<1>(res) << ' ' << std::get<2>(res);
    
    return 0;
}
