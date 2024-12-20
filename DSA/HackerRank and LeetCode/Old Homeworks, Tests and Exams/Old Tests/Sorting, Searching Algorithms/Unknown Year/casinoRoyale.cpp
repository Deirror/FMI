#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[int(1e6)];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0){
            cout << arr[i] << '\n';
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 1){
            cout << arr[i] << '\n';
        }
    }

    return 0;
}
