#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binary_find(int* arr, int n, int searched) {
    int left = 0;
    int right = n - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == searched) {
            return mid;
        }
        
        if(arr[left] > arr[mid]) {
            if(arr[left] <= searched) {
                right = mid - 1;
            } else {
                if(arr[mid] < searched){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        } else {
            if(arr[left] <= searched) {
                 if(arr[mid] < searched){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                left = mid + 1;
            }
        }
    }
    
    return -1;
}

int arr[3*int(1e6) + 7];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int searched;
        cin >> searched;
        
        cout << binary_find(arr, n, searched) << '\n';
    }
    return 0;
}
