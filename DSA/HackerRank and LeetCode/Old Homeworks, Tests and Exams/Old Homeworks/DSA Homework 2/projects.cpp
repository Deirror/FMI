#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool my_binary_search(int* arr, int n, int searched) {
    int left = 0;
    int right = n - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == searched) {
            return true;
        } else if (arr[mid] < searched) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

int arr[int(1e6)];

int main() {
    int n, d;
    cin >> n >> d;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(my_binary_search(arr, n, (arr[i] - d))) {
            count++;
        }
    }
    
    cout << count;
    
    return 0;
}
