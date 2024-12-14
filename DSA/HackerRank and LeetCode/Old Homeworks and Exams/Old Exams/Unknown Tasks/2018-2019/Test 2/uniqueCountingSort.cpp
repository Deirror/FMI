#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int counting_sort(int* arr, int n) {
    int copy_arr[n]{};
    for(int i = 0; i < n; i++) {
        copy_arr[i] = arr[i];
    }
    
    int hist[int(1e4) + 3]{};
    for(int i = 0; i < n; i++) {
        hist[arr[i]] = 1;
    }
    
    for(int i = 1; i < int(1e4); i++) {
        hist[i] += hist[i - 1];
    }
    
    int new_size = 0;
    for(int i = n - 1; i >= 0; i--) {
        int ch_count = hist[copy_arr[i]];
        if(ch_count > 0) {
            arr[ch_count - 1] = copy_arr[i];
            new_size++;
        }
        hist[copy_arr[i]] = 0;
    }
    
    return new_size;
}

int arr[int(1e7) + 3];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int size = counting_sort(arr, n);
    
    for(int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    
    return 0;
}
