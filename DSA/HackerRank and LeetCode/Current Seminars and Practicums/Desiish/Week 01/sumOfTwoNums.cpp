#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binary_search_idx_excl(int* arr, int left, int right, int searched,int idx_excl) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == searched && mid != idx_excl) return mid;
        
        if(arr[mid] < searched) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    int arr[N];
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < N; i++) {
        int idx = binary_search_idx_excl(arr, 0, N - 1, K - arr[i], i);
        
        if(idx != -1) {
            cout << i << ' ' << idx;
            break;
        }
    }
    
    return 0;
}
