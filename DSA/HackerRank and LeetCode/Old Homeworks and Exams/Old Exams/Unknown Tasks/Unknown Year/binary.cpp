#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[int(1e6)];

pair<int, int> binary_search_find_level(int* arr, int n, int searched) {
    int left = 0;
    int right = n - 1;
    
    int level = 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == searched) {
            return make_pair(mid, level);
        }
        
        if(arr[mid] > searched) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        
        level++;
    }
    
    return make_pair(-1, level - 1);
}

int main() {
    int n, k;
    cin >> n;
    
    for(int i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    
    cin >> k;
    pair<int, int> res[k];
    for(int i = 0; i < k; i++) {
        int searched;
        cin >> searched;
        res[i] = binary_search_find_level(arr, n, searched);
        cout << res[i].first << ' ';
    }
    
    cout << '\n';
    
    for(int i = 0; i < k; i++) {
        cout << res[i].second << ' ';
    }
    
    return 0;
}
